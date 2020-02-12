package fast_modular_exponentiation;

/**
 * when same input is given;
 * simpleFastModularExponentiation lasts 22ms,
 * fastModularExponentiation lasts 2ms
 */
public class FastModularExponentiation {

    /**
     * https://www.wikizeroo.org/wiki/en/Modular_exponentiation
     *
     * start with `result` = 0
     * repeat `exponent` times: result = (result * base) % mod
     *
     * @param base base
     * @param exponent exponent
     * @param mod mod
     * @return result
     */
    public static int simpleFastModularExponentiation(int base, int exponent, int mod) {

        int result = 1;

        base = base % mod;

        for (int i = 0; i < exponent; i++) {
            result = (result * base) % mod;
        }

        return result;
    }

    /**
     * https://en.wikipedia.org/wiki/Exponentiation_by_squaring
     * 2^k-ary method implementation
     * @param base base
     * @param exponent exponent
     * @param mod mod
     * @return result
     */
    public static int fastModularExponentiation(int base, int exponent, int mod) {

        int result = 1;

        while(true) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }

            exponent /= 2;

            if (exponent == 0) {
                break;
            }

            base = (base * base) % mod;
        }

        return result;
    }

}
