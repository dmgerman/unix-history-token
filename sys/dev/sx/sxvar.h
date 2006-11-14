begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Device driver for Specialix I/O8+ multiport serial card.  *  * Copyright 2003 Frank Mayhar<frank@exit.com>  *  * Derived from the "si" driver by Peter Wemm<peter@netplex.com.au>, using  * lots of information from the Linux "specialix" driver by Roger Wolff  *<R.E.Wolff@BitWizard.nl> and from the Intel CD1865 "Intelligent Eight-  * Channel Communications Controller" datasheet.  Roger was also nice  * enough to answer numerous questions about stuff specific to the I/O8+  * not covered by the CD1865 datasheet.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notices, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notices, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN  * NO EVENT SHALL THE AUTHORS BE LIABLE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|sxattach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sx_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|sx_devclass
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sx_softc
block|{
name|struct
name|sx_port
modifier|*
name|sc_ports
decl_stmt|;
comment|/* port structures for this card */
name|int
name|sc_irq
decl_stmt|;
comment|/* copy of attach irq */
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
name|int
name|sc_io_rid
decl_stmt|;
name|int
name|sc_irq_rid
decl_stmt|;
name|int
name|sc_unit
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|SX_DEBUG
end_ifdef

begin_comment
comment|/*  * debugging stuff  */
end_comment

begin_function_decl
name|void
name|sx_dprintf
parameter_list|(
name|struct
name|sx_port
modifier|*
name|pp
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|x
parameter_list|)
value|sx_dprintf x
end_define

begin_define
define|#
directive|define
name|DBG_ENTRY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DBG_DRAIN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DBG_OPEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DBG_CLOSE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DBG_READ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DBG_WRITE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DBG_PARAM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DBG_INTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DBG_IOCTL
value|0x00000100
end_define

begin_comment
comment|/*			0x00000200 */
end_comment

begin_define
define|#
directive|define
name|DBG_SELECT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DBG_OPTIM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DBG_START
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DBG_EXIT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DBG_FAIL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DBG_STOP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DBG_AUTOBOOT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DBG_MODEM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DBG_DOWNLOAD
value|0x00040000
end_define

begin_comment
comment|/*			0x00080000*/
end_comment

begin_define
define|#
directive|define
name|DBG_POLL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DBG_ALL
value|0xffffffff
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* void */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

