package bankAccount;

public class Account {

	private String name;
	private long amount;

	Account(String name, long amount) {
		this.name = name;
		setAmount(amount);
	}

	public void deposit(long amount) {
		this.amount += amount;
	}

	public String getName() {
		return name;
	}

	public long getAmount() {
		return amount;
	}

	public void setAmount(long amount) {
		this.amount = amount;
	}

}
