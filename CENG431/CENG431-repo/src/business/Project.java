package business;

import java.io.Serializable;
import java.util.Date;

public class Project implements Serializable {

    private String name;
    private String description;
    private Date startDate;

    public Project(String name, String description, Date startDate) {
        setName(name);
        setDescription(description);
        setStartDate(startDate);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name == null || name.equals(""))
            throw new IllegalArgumentException("name can not be null or empty.");
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        if (description == null || description.equals(""))
            throw new IllegalArgumentException("description can not be null or empty.");
        this.description = description;
    }

    public Date getStartDate() {
        return startDate;
    }

    public void setStartDate(Date startDate) {
        if (startDate == null)
            throw new IllegalArgumentException("startDate can not be null.");
        this.startDate = startDate;
    }

}