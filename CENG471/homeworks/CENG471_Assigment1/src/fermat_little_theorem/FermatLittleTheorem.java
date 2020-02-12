package fermat_little_theorem;

import euclid_extended_algorithm.EuclidExtendedAlgorithm;

import java.math.BigInteger;

public class FermatLittleTheorem {

    /**
     * Fermat's Little Theorem:
     * If n is a prime number, then for every a, 1 < a < n-1
     *
     * a^(n-1) ≡ 1 (mod n)
     * OR
     * a^(n-1) % n = 1
     *
     * @param number number
     * @return is given number prime or not
     */
    public static boolean isPrime(BigInteger number) {

        if (number.compareTo(BigInteger.ONE) <= 0)
            return false;

        for (BigInteger a = BigInteger.valueOf(2); a.compareTo(number) < 0; a = a.add(BigInteger.ONE)) {
            if (!EuclidExtendedAlgorithm.greatestCommonDivisor(a, number).equals(BigInteger.ONE)) {
                return false;
            }
        }
        return true;
    }

}
