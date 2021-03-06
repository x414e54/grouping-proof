#include <cutter.h>

#include <nfc/nfc.h>
#include "chips/pn53x.h"

#define MAX_DEVICE_COUNT 1
#define MAX_TARGET_COUNT 1

void
test_register_endianness (void)
{
    nfc_device_desc_t devices[MAX_DEVICE_COUNT];
    size_t device_count;
    bool res;

    nfc_list_devices (devices, MAX_DEVICE_COUNT, &device_count);
    if (!device_count)
	cut_omit ("No NFC device found");

    nfc_device_t *device;

    device = nfc_connect (&(devices[0]));
    cut_assert_not_null (device, cut_message ("nfc_connect"));

    uint8_t value;

    /* Set a 0xAA test value in writable register memory to test register access */
    res = pn53x_write_register (device, PN53X_REG_CIU_TxMode, 0xFF, 0xAA);
    cut_assert_true (res, cut_message ("write register value to 0xAA"));

    /* Get test value from register memory */
    res = pn53x_read_register (device, PN53X_REG_CIU_TxMode, &value);
    cut_assert_true (res, cut_message ("read register value"));
    cut_assert_equal_uint (0xAA, value, cut_message ("check register value"));

    /* Set a 0x55 test value in writable register memory to test register access */
    res = pn53x_write_register (device, PN53X_REG_CIU_TxMode, 0xFF, 0x55);
    cut_assert_true (res, cut_message ("write register value to 0x55"));

    /* Get test value from register memory */
    res = pn53x_read_register (device, PN53X_REG_CIU_TxMode, &value);
    cut_assert_true (res, cut_message ("read register value"));
    cut_assert_equal_uint (0x55, value, cut_message ("check register value"));

    nfc_disconnect (device);
}
