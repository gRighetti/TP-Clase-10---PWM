#include "bsp/bsp.h"

void APP_1ms(void);

#define INCREASE 1
#define DECREASE 0

uint8_t brightness = 0;
uint8_t intensity = 1;
uint16_t counter = 30;
uint16_t counterTimer = 80;
int8_t estado = 0;

int main(void) {

	BSP_Init();

	while (1) {
		if (Get_SW_State()) {
			if (!counterTimer) {
				estado++;
				if (estado > 3) {
					estado = 0;
				}
				counterTimer = 80;
			}
			if (!counter) {

				counter = 30;
				if (brightness < 100)
					brightness++;
			}
		} else {
			if (!counterTimer) {
				estado--;
				if (estado < 0) {
					estado = 3;
				}
				counterTimer = 80;
			}
			if (!counter) {

				counter = 30;
				if (brightness > 0)
					brightness--;
			}
		}

		switch (estado) {
		case 0:
			led_setBright(LED_AZUL, brightness);
			led_setBright(LED_ROJO, 0);
			led_setBright(LED_NARANJA, 0);
			led_setBright(LED_VERDE, 0);

			break;

		case 1:
			led_setBright(LED_ROJO, brightness);
			led_setBright(LED_AZUL, 0);
			led_setBright(LED_NARANJA, 0);
			led_setBright(LED_VERDE, 0);
			break;

		case 2:
			led_setBright(LED_NARANJA, brightness);
			led_setBright(LED_AZUL, 0);
			led_setBright(LED_ROJO, 0);
			led_setBright(LED_VERDE, 0);
			break;

		case 3:
			led_setBright(LED_VERDE, brightness);
			led_setBright(LED_AZUL, 0);
			led_setBright(LED_ROJO, 0);
			led_setBright(LED_NARANJA, 0);
			break;

		}

	}
}

void APP_1ms(void) {

	if (counter) {
		counter--;
	}
	if (counterTimer) {
		counterTimer--;
	}

}
