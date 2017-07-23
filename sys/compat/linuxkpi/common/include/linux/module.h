begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MODULE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MODULE_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/list.h>
end_include

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/kmod.h>
end_include

begin_include
include|#
directive|include
file|<linux/kobject.h>
end_include

begin_include
include|#
directive|include
file|<linux/sysfs.h>
end_include

begin_include
include|#
directive|include
file|<linux/moduleparam.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_define
define|#
directive|define
name|MODULE_AUTHOR
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_DESCRIPTION
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_LICENSE
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_INFO
parameter_list|(
name|tag
parameter_list|,
name|info
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_FIRMWARE
parameter_list|(
name|firmware
parameter_list|)
end_define

begin_define
define|#
directive|define
name|THIS_MODULE
value|((struct module *)0)
end_define

begin_define
define|#
directive|define
name|EXPORT_SYMBOL
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EXPORT_SYMBOL_GPL
parameter_list|(
name|name
parameter_list|)
end_define

begin_comment
comment|/* OFED pre-module initialization */
end_comment

begin_define
define|#
directive|define
name|SI_SUB_OFED_PREINIT
value|(SI_SUB_ROOT_CONF - 2)
end_define

begin_comment
comment|/* OFED default module initialization */
end_comment

begin_define
define|#
directive|define
name|SI_SUB_OFED_MODINIT
value|(SI_SUB_ROOT_CONF - 1)
end_define

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_function
specifier|static
specifier|inline
name|void
name|_module_run
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|OFED_DEBUG_INIT
name|char
name|name
index|[
literal|1024
index|]
decl_stmt|;
name|caddr_t
name|pc
decl_stmt|;
name|long
name|offset
decl_stmt|;
name|pc
operator|=
operator|(
name|caddr_t
operator|)
name|arg
expr_stmt|;
if|if
condition|(
name|linker_search_symbol_name
argument_list|(
name|pc
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|,
operator|&
name|offset
argument_list|)
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"Running ??? (%p)\n"
argument_list|,
name|pc
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Running %s (%p)\n"
argument_list|,
name|name
argument_list|,
name|pc
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fn
operator|=
name|arg
expr_stmt|;
name|DROP_GIANT
argument_list|()
expr_stmt|;
name|fn
argument_list|()
expr_stmt|;
name|PICKUP_GIANT
argument_list|()
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|module_init
parameter_list|(
name|fn
parameter_list|)
define|\
value|SYSINIT(fn, SI_SUB_OFED_MODINIT, SI_ORDER_FIRST, _module_run, (fn))
end_define

begin_define
define|#
directive|define
name|module_exit
parameter_list|(
name|fn
parameter_list|)
define|\
value|SYSUNINIT(fn, SI_SUB_OFED_MODINIT, SI_ORDER_SECOND, _module_run, (fn))
end_define

begin_comment
comment|/*  * The following two macros are a workaround for not having a module  * load and unload order resolver:  */
end_comment

begin_define
define|#
directive|define
name|module_init_order
parameter_list|(
name|fn
parameter_list|,
name|order
parameter_list|)
define|\
value|SYSINIT(fn, SI_SUB_OFED_MODINIT, (order), _module_run, (fn))
end_define

begin_define
define|#
directive|define
name|module_exit_order
parameter_list|(
name|fn
parameter_list|,
name|order
parameter_list|)
define|\
value|SYSUNINIT(fn, SI_SUB_OFED_MODINIT, (order), _module_run, (fn))
end_define

begin_define
define|#
directive|define
name|module_get
parameter_list|(
name|module
parameter_list|)
end_define

begin_define
define|#
directive|define
name|module_put
parameter_list|(
name|module
parameter_list|)
end_define

begin_define
define|#
directive|define
name|try_module_get
parameter_list|(
name|module
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MODULE_H_ */
end_comment

end_unit

