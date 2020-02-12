package fermat_little_theorem;

import org.junit.jupiter.api.Test;

import java.math.BigInteger;

import static org.junit.jupiter.api.Assertions.*;

public class FermatLittleTheoremTest {

    @Test
    public void it_should_find_if_number_is_prime_or_not() {
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(-1)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(0)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(1)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(2)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(3)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(4)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(5)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(6)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(7)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(8)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(9)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(10)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(11)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(12)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(13)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(17)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(19)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(23)));
        assertFalse(FermatLittleTheorem.isPrime(BigInteger.valueOf(25)));
        assertTrue(FermatLittleTheorem.isPrime(BigInteger.valueOf(29)));
    }

}
