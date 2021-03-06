/****************************************************************************
 * drivers/dev_err.c
 * Global stderr stream driver
 *
 *   Copyright (C) 2015 Haltian Ltd. All rights reserved.
 *   Author: Roman Saveljev <roman.saveljev@haltian.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <nuttx/fs/fs.h>
#include <arch/sim_stderr.h>

#ifndef CONFIG_ARCH_SIM
#error "Currently, /dev/err only compiles for simulator"
#endif /* CONFIG_ARCH_SIM */

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static ssize_t deverr_write(FAR struct file *, FAR const char *, size_t);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations deverr_fops =
{
  0,             /* open */
  0,             /* close */
  0,             /* read */
  deverr_write,  /* write */
  0,             /* seek */
  0,             /* ioctl */
  0              /* poll */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: devnull_write
 ****************************************************************************/

static ssize_t deverr_write(FAR struct file *filep, FAR const char *buffer, size_t len)
{
  return sim_stderr_write(buffer, len);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: deverr_register
 *
 * Description:
 *   Register /dev/err
 *
 ****************************************************************************/

void deverr_register(void)
{
  (void)register_driver("/dev/err", &deverr_fops, 0222, NULL);
}
