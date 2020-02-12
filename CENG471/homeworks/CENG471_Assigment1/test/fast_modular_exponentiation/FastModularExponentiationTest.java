package fast_modular_exponentiation;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class FastModularExponentiationTest {

    @Test
    public void it_should_calculate_simply_fast_modular_exponentiation() {
        assertEquals(3, FastModularExponentiation.simpleFastModularExponentiation(7, 4, 11));
        assertEquals(2, FastModularExponentiation.simpleFastModularExponentiation(7, 13, 11));
        assertEquals(3, FastModularExponentiation.simpleFastModularExponentiation(12, 53, 7));
        assertEquals(1, FastModularExponentiation.simpleFastModularExponentiation(7, 12, 10));
        assertEquals(1, FastModularExponentiation.simpleFastModularExponentiation(3, 51, 13));
    }

    @Test
    public void it_should_calculate_2k_ary_fast_modular_exponentiation() {
        assertEquals(3, FastModularExponentiation.fastModularExponentiation(7, 4, 11));
        assertEquals(2, FastModularExponentiation.fastModularExponentiation(7, 13, 11));
        assertEquals(3, FastModularExponentiation.fastModularExponentiation(12, 53, 7));
        assertEquals(1, FastModularExponentiation.fastModularExponentiation(7, 12, 10));
        assertEquals(1, FastModularExponentiation.fastModularExponentiation(3, 51, 13));
    }

}
