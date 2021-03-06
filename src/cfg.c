/*
 * Ground Station Core (GSC)
 * Copyright (C) 2021  International Space University
 * Contributors:
 *   Stanislav Barantsev

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "log.h"
#include "cfg.h"

cfg_t *_cfg;

cfg_t *alloc_cfg(void)
{
	_cfg = calloc(sizeof(cfg_t), 1);
	if (!_cfg)
		return NULL;

	return _cfg;
}

void destroy_cfg(cfg_t *cfg)
{
	if (cfg) {
		free(cfg);
		cfg = NULL;
	}
}

bool verify_ip(const char *ip)
{
	struct sockaddr_in addr_in;

	if (inet_pton(AF_INET, ip, &addr_in.sin_addr) != 1) {
		LOG_E("Error on inet_pton");
		return false;
	}
	return true;
}

cfg_t *cfg_global_get(void)
{
	return _cfg;
}
