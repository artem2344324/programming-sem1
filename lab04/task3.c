#include <locale.h>
#include <stdint.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define ADC_MASK      0x03FFU 
#define RDY_SHIFT     10U
#define RDY_MASK      0x0001U 
#define TEMP_SHIFT    11U
#define TEMP_MASK     0x001FU 

/* Прототипи функцій */
void init_console_utf8(void);
uint16_t pack_telemetry(uint16_t adc_value, uint8_t data_ready, uint8_t chip_temp);
void unpack_telemetry(uint16_t packet, uint16_t *adc_value, uint8_t *data_ready, uint8_t *chip_temp);

int main(void) {
    init_console_utf8();

    uint16_t in_adc = 742U;  
    uint8_t in_ready = 1U;   
    uint8_t in_temp = 27U;       

    uint16_t packet = pack_telemetry(in_adc, in_ready, in_temp);

    uint16_t out_adc = 0U;
    uint8_t out_ready = 0U;
    uint8_t out_temp = 0U;

    unpack_telemetry(packet, &out_adc, &out_ready, &out_temp);

    printf("Початкові параметри: ADC=%u, Ready=%u, Temp=%u\n", in_adc, in_ready, in_temp);
    printf("Запакований пакет:   0x%04X (16-bit) / 0x%08X (32-bit)\n", packet, (uint32_t)packet);
    printf("Розпаковані дані:    ADC=%u, Ready=%u, Temp=%u\n", out_adc, out_ready, out_temp);

    if (in_adc == out_adc && in_ready == out_ready && in_temp == out_temp) {
        printf("Результат: параметри відновлено повністю ідентично.\n");
    } else {
        printf("Результат: виявлено розбіжність параметрів!\n");
    }
    fflush(stdout);

    return 0;
}

void init_console_utf8(void) {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    setlocale(LC_CTYPE, ".UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(65001U);
    SetConsoleCP(65001U);
#endif
}

uint16_t pack_telemetry(uint16_t adc_value, uint8_t data_ready, uint8_t chip_temp) {
    uint16_t adc_part = (uint16_t)(adc_value & ADC_MASK);
    uint16_t rdy_part = (uint16_t)(((uint16_t)(data_ready & RDY_MASK)) << RDY_SHIFT);
    uint16_t temp_part = (uint16_t)(((uint16_t)(chip_temp & TEMP_MASK)) << TEMP_SHIFT);

    return (uint16_t)(adc_part | rdy_part | temp_part);
}

void unpack_telemetry(uint16_t packet, uint16_t *adc_value, uint8_t *data_ready, uint8_t *chip_temp) {
    if (adc_value != NULL) {
        *adc_value = (uint16_t)(packet & ADC_MASK);
    }
    if (data_ready != NULL) {
        *data_ready = (uint8_t)((packet >> RDY_SHIFT) & RDY_MASK);
    }
    if (chip_temp != NULL) {
        *chip_temp = (uint8_t)((packet >> TEMP_SHIFT) & TEMP_MASK);
    }
}