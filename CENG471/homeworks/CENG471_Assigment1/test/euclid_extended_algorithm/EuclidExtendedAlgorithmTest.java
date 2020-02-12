package euclid_extended_algorithm;

import org.junit.jupiter.api.Test;

import java.math.BigInteger;

import static org.junit.jupiter.api.Assertions.*;

public class EuclidExtendedAlgorithmTest {

    @Test
    public void it_should_calculate_multiplicative_inverse() {
        assertThrows(ArithmeticException.class, () -> EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(0), BigInteger.valueOf(0)));
        assertThrows(ArithmeticException.class, () -> EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(1), BigInteger.valueOf(0)));
        assertThrows(ArithmeticException.class, () -> EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(0), BigInteger.valueOf(1)));
        assertThrows(ArithmeticException.class, () -> EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(1), BigInteger.valueOf(1)));
        assertThrows(ArithmeticException.class, () -> EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(-1), BigInteger.valueOf(0)));
        assertEquals(BigInteger.valueOf(4), EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(3), BigInteger.valueOf(11)));
        assertEquals(BigInteger.valueOf(2), EuclidExtendedAlgorithm.multiplicativeInverse(BigInteger.valueOf(13), BigInteger.valueOf(25)));
    }

    @Test
    public void it_should_calculate_greatest_common_divisor() {
        assertThrows(ArithmeticException.class, () -> EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(0), BigInteger.valueOf(0)));
        assertEquals(BigInteger.valueOf(1), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(0), BigInteger.valueOf(1)));
        assertEquals(BigInteger.valueOf(1), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(1), BigInteger.valueOf(0)));
        assertEquals(BigInteger.valueOf(1), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(1), BigInteger.valueOf(1)));
        assertEquals(BigInteger.valueOf(2), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(0), BigInteger.valueOf(2)));
        assertEquals(BigInteger.valueOf(2), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(2), BigInteger.valueOf(0)));
        assertEquals(BigInteger.valueOf(1), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(3), BigInteger.valueOf(7)));
        assertEquals(BigInteger.valueOf(4), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(12), BigInteger.valueOf(8)));
        assertEquals(BigInteger.valueOf(4), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(8), BigInteger.valueOf(12)));
        assertEquals(BigInteger.valueOf(12), EuclidExtendedAlgorithm.greatestCommonDivisor(BigInteger.valueOf(12), BigInteger.valueOf(12)));
    }

    @Test
    public void it_should_calculate_relatively_prime() {
        assertFalse(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(0), BigInteger.valueOf(10)));
        assertFalse(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(0), BigInteger.valueOf(1)));
        assertFalse(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(1), BigInteger.valueOf(0)));
        assertTrue(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(1), BigInteger.valueOf(1)));
        assertTrue(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(3), BigInteger.valueOf(11)));
        assertFalse(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(4), BigInteger.valueOf(12)));
        assertFalse(EuclidExtendedAlgorithm.relativelyPrime(BigInteger.valueOf(12), BigInteger.valueOf(12)));
    }

}