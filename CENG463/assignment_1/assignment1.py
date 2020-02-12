# CENG 463 Assignment1 by
# Ahmet Semsettin Ozdemirden
# StudentNo: 230201043
# Date: 03-2019
import random
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import multivariate_normal

from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter

def loadWineData(filename):
    with open(filename) as f:
        content = f.readlines()
    return [[float(y) for y in x.strip().split(",")] for x in content] 

def selectAttributes(wineData, attr1, attr2):
    return [[int(x[0]), x[attr1], x[attr2]] for x in wineData] 

def partitionData(wineData, percentage):
    num = int(len(wineData) * percentage)
    shuffled = wineData[:]
    random.shuffle(shuffled)
    return shuffled[:num], shuffled[num:]

def decomposeWineData(data):
    # dictionary = { 1: [[13.58, 13.4, ...], [2.58, 4.6, ...]], 2: [...}
    dictionary = { "class1": [[], []], "class2": [[], []], "class3": [[], []] }
    for e in data:
        dictionary["class" + str(e[0])][0].append(e[1])
        dictionary["class" + str(e[0])][1].append(e[2])
    return dictionary

def calculateMaximumLikelihoodEstimations(data):
    # create MLE dictionary
    MLE = { "class1": { "meanVector": [], "covarianceMatrix": [] }, "class2": { "meanVector": [], "covarianceMatrix": [] }, "class3": { "meanVector": [], "covarianceMatrix": [] } }
    for i in range(1, 4):
        classData = data["class" + str(i)]
        # convert arrays to numpy arrays
        classData[0] = np.array(classData[0])
        classData[1] = np.array(classData[1])
        # calculate mean and covariance by using numpy
        MLE["class" + str(i)]["meanVector"] = np.array([np.mean(classData[0]), np.mean(classData[1])])
        MLE["class" + str(i)]["covarianceMatrix"] = np.cov(classData[0], classData[1])
    return MLE

def plot(classData, classMLE):
    # https://matplotlib.org/1.3.1/mpl_toolkits/mplot3d/tutorial.html#surface-plots

    # calculates X, Y, Z axis values
    N = 120
    # Mean - 8 * Standard Deviation gives us boundary of X and Y for standard gaussian distribution
    X = np.linspace(classMLE["meanVector"][0] - 8*classMLE["covarianceMatrix"][0][0], classMLE["meanVector"][0] + 8*classMLE["covarianceMatrix"][0][0], N)
    Y = np.linspace(classMLE["meanVector"][1] - 8*classMLE["covarianceMatrix"][1][1], classMLE["meanVector"][1] + 8*classMLE["covarianceMatrix"][1][1], N)
    X, Y = np.meshgrid(X, Y)
    pos = np.dstack((X, Y))

    rv = multivariate_normal(mean=classMLE["meanVector"], cov=classMLE["covarianceMatrix"])
    Z = rv.pdf(pos)

    # plot initialization
    fig = plt.figure()
    ax = fig.gca(projection='3d')

    # plot the surface
    surf = ax.plot_surface(X, Y, Z, rstride=3, cstride=3, linewidth=1, antialiased=False,
                    cmap=cm.viridis)
                        
    # customize the z axis
    ax.zaxis.set_major_locator(LinearLocator(10))
    ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

    # draw a color bar which maps values to colors
    fig.colorbar(surf, shrink=0.5, aspect=5)

    plt.show()


def main():
    # load and parse wine data
    allWineData = loadWineData("wine.data.txt")
    # select attributes, since first attribute is class information attribute selection should from 1
    wineData = selectAttributes(allWineData, 6, 10)
    # partition wine data into training and test
    trainingData, testData = partitionData(wineData, 0.8)
    # decompose training data into classes
    # decomposed winedata: { "class1": [[<attr1>], [<attr2>]], "class2": [[<attr1>], [<attr2>]], "class3": [[<attr1>], [<attr2>]] }
    decomposedTrainingData = decomposeWineData(trainingData)
    # calculate MLE
    # MLE = { "class1": { "meanVector": [...], "covarianceMatrix": [...] }, "class2": { "meanVector": [...], "covarianceMatrix": [...] }, "class3": { "meanVector": [...], "covarianceMatrix": [...] } }
    MLE = calculateMaximumLikelihoodEstimations(decomposedTrainingData)
    # plot 2D gaussian for each class
    for i in range(1, 4):
        plot(decomposedTrainingData["class" + str(i)], MLE["class" + str(i)])

    # probability density function (likelihood)
    PDF = {}
    for i in range(1, 4):
        classMLE = MLE["class" + str(i)]
        PDF["class" + str(i)] = multivariate_normal(mean=classMLE["meanVector"], cov=classMLE["covarianceMatrix"])

    # priors
    classPriors = {}
    for i in range(1, 4):
        classPriors["class" + str(i)] = len(decomposedTrainingData["class" + str(i)][0]) / len(trainingData)
    
    # make predictions
    successfulPrediction = 0

    # loop for test data in class order
    for elemTestData in testData:
        # find posterior for each class in test data
        classPosterior = {}
        for classNo in range(1, 4):
            classLikelihood = PDF["class" + str(classNo)].pdf((elemTestData[1], elemTestData[2]))
            classPrior = classPriors["class" + str(classNo)]
            classPosterior["class" + str(classNo)] = classLikelihood * classPrior # since evidence is 1, we do not devide

        if findClass(classPosterior) == ("class" + str(elemTestData[0])):
            successfulPrediction += 1

    accuracy = successfulPrediction / len(testData)
    print("accuracy: " + str(accuracy))

# max posterior value is the closest to class
def findClass(classPosterior):
    if classPosterior["class1"] > classPosterior["class2"] and classPosterior["class1"] > classPosterior["class3"]:
        return "class1"
    elif classPosterior["class2"] > classPosterior["class1"] and classPosterior["class2"] > classPosterior["class3"]:
        return "class2"
    elif classPosterior["class3"] > classPosterior["class1"] and classPosterior["class3"] > classPosterior["class2"]:
        return "class3"

print("starting calculations...")
main()