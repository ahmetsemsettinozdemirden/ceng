package data;

import business.Project;

import java.io.*;
import java.util.List;

public class ProjectManagementSystemSerializer {

    // TODO: take care of Exceptions
    private final String filenamePrefix = "Projects-";

    public List<Project> loadLatestProjects() throws Exception {

        File appdata = new File("appdata");
        if (!appdata.exists() || !appdata.isDirectory())
            return null; // TODO: throw exception -> `appdata should exist and be a folder`

        File[] projectsFiles = appdata.listFiles();
        if (projectsFiles == null)
            return null; // TODO: throw exception

        FileInputStream fileInputStream = new FileInputStream(findLatestProjectsFile(projectsFiles));
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
        List<Project> projects = (List<Project>) objectInputStream.readObject();
        objectInputStream.close();
        return projects;
    }

    public void saveProjects(List<Project> projects) throws Exception {
        // TODO: date (YYYY-MM-DD)
        File projectsFile = new File("appdata/Projects-YYYY-MM-DD.txt");
        FileOutputStream fileOutputStream = new FileOutputStream(projectsFile);
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
        objectOutputStream.writeObject(projects);
        objectOutputStream.flush();
        objectOutputStream.close();
    }

    private File findLatestProjectsFile(File[] projectsFiles) {
        // TODO: find based on dates (Projects-YYYY-MM-DD.txt)
        return null;
    }

}
