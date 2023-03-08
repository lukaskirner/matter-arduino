/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include "app_task.h"

#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>
#include <zephyr/usb/usb_device.h>

LOG_MODULE_REGISTER(app, CONFIG_MATTER_LOG_LEVEL_DBG);

int main() {
	CHIP_ERROR err = CHIP_NO_ERROR;

	err = chip::System::MapErrorZephyr(usb_enable(NULL));
	if (err != CHIP_NO_ERROR) {
		LOG_ERR("Failed to initialize USB device");
		return EXIT_FAILURE;
	}

	LOG_DBG("Starting App...");
	err = AppTask::Instance().StartApp();

	LOG_ERR("Exited with code %" CHIP_ERROR_FORMAT, err.Format());
	return err == CHIP_NO_ERROR ? EXIT_SUCCESS : EXIT_FAILURE;
}
