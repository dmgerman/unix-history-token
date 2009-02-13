begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-     ----------------------------------------------------------------------      Copyright (C) 2000  Cesar Miquel  (miquel@df.uba.ar)      Redistribution and use in source and binary forms, with or without     modification, are permitted under any licence of your choise which     meets the open source licence definiton     http://www.opensource.org/opd.html such as the GNU licence or the     BSD licence.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     General Public License or the BSD license for more details.      ----------------------------------------------------------------------      Modified for FreeBSD by Iwasa Kazmi<kzmi@ca2.so-net.ne.jp>      ---------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USB_VENDOR_DIAMOND
end_ifndef

begin_define
define|#
directive|define
name|USB_VENDOR_DIAMOND
value|0x841
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_PRODUCT_DIAMOND_RIO500USB
end_ifndef

begin_define
define|#
directive|define
name|USB_PRODUCT_DIAMOND_RIO500USB
value|0x1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|RioCommand
block|{
name|u_int16_t
name|length
decl_stmt|;
name|int
name|request
decl_stmt|;
name|int
name|requesttype
decl_stmt|;
name|int
name|value
decl_stmt|;
name|int
name|index
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
name|int
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RIO_SEND_COMMAND
value|_IOWR('U', 200, struct RioCommand)
end_define

begin_define
define|#
directive|define
name|RIO_RECV_COMMAND
value|_IOWR('U', 201, struct RioCommand)
end_define

begin_define
define|#
directive|define
name|RIO_DIR_OUT
value|0x0
end_define

begin_define
define|#
directive|define
name|RIO_DIR_IN
value|0x1
end_define

end_unit

