package business;

import java.io.Serializable;
import java.util.Date;

public class Activity implements Serializable {

    private int number;
    private String description;
    private Date startDate;

    // TODO: what does `deliverable` mean?
    private String deliverable;

    // TODO: deliverable
    public Activity(int number, String description, Date startDate) {
        setNumber(number);
        setDescription(description);
        setStartDate(startDate);
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        if (number < 0)
            throw new IllegalArgumentException("number can not be less than 0.");
        this.number = number;
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

    // TODO: implement getHours
    public int getHours() {
        return 0;
    }

    // TODO: deliverable getter and setter

}
