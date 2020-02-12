package development.test;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ TestCalculation.class, TestCompany.class, TestFileParser.class, TestVehicle.class })
public class AllTests {

}
