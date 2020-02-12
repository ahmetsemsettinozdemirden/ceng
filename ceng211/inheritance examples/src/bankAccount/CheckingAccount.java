package bankAccount;

public class CheckingAccount extends Account {

	CheckingAccount(long amount) {
		super("checking", amount);
	}

	public void withdraw(long amount) {
		setAmount(getAmount() - amount);
	}

}
