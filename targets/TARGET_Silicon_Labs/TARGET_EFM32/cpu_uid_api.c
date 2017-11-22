/***************************************************************************//**
 * @file cpu_uid_api.c
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2017 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#include "device.h"

#if DEVICE_CPUUID

#include "em_system.h"
#include "cpu_uid_api.h"

#define UID_LENGTH      8

int cpu_uid_get_length(void)
{
    return UID_LENGTH;
}

void cpu_uid_get_uid(uint8_t *uid)
{
    int pos = 0;
    uint64_t tempuid = SYSTEM_GetUnique();

    for (int i = (UID_LENGTH-1); i >= 0; --i)
    {
        uid[pos] = (uint8_t)((tempuid >> (i*8)) & 0xFF);
        ++pos;
    }
}

#endif
