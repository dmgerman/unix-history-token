begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dmzreg.h	7.2 (Berkeley) 2/19/87  */
end_comment

begin_comment
comment|/*  * Registers for DMZ-32.  * Defined in terms of dmx_octet common registers.  */
end_comment

begin_struct
struct|struct
name|dmzdevice
block|{
name|short
name|dmz_config
decl_stmt|;
comment|/* configuration csr */
name|short
name|dmz_diag
decl_stmt|;
comment|/* diagnostic csr */
name|struct
name|dmx_octet
name|dmz_octet
index|[
literal|3
index|]
decl_stmt|;
comment|/* per-octet registers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DMZ
parameter_list|(
name|a
parameter_list|)
value|(a/24)
end_define

begin_define
define|#
directive|define
name|OCTET
parameter_list|(
name|a
parameter_list|)
value|((a%24)/8)
end_define

begin_define
define|#
directive|define
name|LINE
parameter_list|(
name|a
parameter_list|)
value|((a%24)%8)
end_define

begin_define
define|#
directive|define
name|DMZ_NOC_MASK
value|03
end_define

begin_define
define|#
directive|define
name|DMZ_INTERFACE
value|000
end_define

end_unit

