package euclid_extended_algorithm;

import java.math.BigInteger;

public class EuclidExtendedAlgorithm {

    /***
     * take modular inverse of given number
     *
     * about Arithmetic Exception
     * https://math.stackexchange.com/questions/516251/why-is-n-mod-0-undefined
     * @param number
     * @param mod
     * @return multiplicative inverse
     */
    public static BigInteger multiplicativeInverse(BigInteger number, BigInteger mod) {

        if(number.compareTo(mod.subtract(BigInteger.ONE)) > 0)
            throw new ArithmeticException(String.format("number {0, 1, 2, … mod-1}, i.e., in the range of integer mod! number: %d, mod: %d", number, mod));

        if (mod.equals(BigInteger.ZERO))
            throw new ArithmeticException("mod can not be 0!");

        number = number.mod(mod);
        for (BigInteger incrementalNumber = BigInteger.ONE; incrementalNumber.compareTo(mod) < 0; incrementalNumber = incrementalNumber.add(BigInteger.ONE)) {
            if ((number.multiply(incrementalNumber)).mod(mod).equals(BigInteger.ONE)) {
                return incrementalNumber;
            }
        }

        throw new ArithmeticException(String.format("Multiplicative inverse of %d mod %d could not found!", number, mod));
    }

    /**
     * find greatest common divisor of given 2 numbers
     *
     * @param number1 first number
     * @param number2 second number
     * @return greatest common divisor
     */
    public static BigInteger greatestCommonDivisor(BigInteger number1, BigInteger number2) {

        if (number1.compareTo(BigInteger.ZERO) <= 0 && number2.compareTo(BigInteger.ZERO) <= 0)
            throw new ArithmeticException("both numbers can not be 0 or less!");

        if (number1.equals(BigInteger.ZERO))
            return number2;

        if (number2.equals(BigInteger.ZERO))
            return number1;

        return greatestCommonDivisor(number2, number1.mod(number2));
    }

    /**
     * check if given two numbers are relatively prime or not
     *
     * @param number1 first number
     * @param number2 second number
     * @return prime or not
     */
    public static boolean relativelyPrime(BigInteger number1, BigInteger number2) {

        if (number1.compareTo(BigInteger.ZERO) <= 0 || number2.compareTo(BigInteger.ZERO) <= 0)
            return false;

        return greatestCommonDivisor(number1, number2).equals(BigInteger.ONE);
    }

}
