begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *      @(#)if_llc.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * IEEE 802.2 Link Level Control headers, for use in conjunction with  * 802.{3,4,5} media access control methods.  *  * Headers here do not use bit fields due to shortcommings in many  * compilers.  */
end_comment

begin_struct
struct|struct
name|llc
block|{
name|u_char
name|llc_dsap
decl_stmt|;
name|u_char
name|llc_ssap
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_char
name|control
decl_stmt|;
name|u_char
name|format_id
decl_stmt|;
name|u_char
name|class
decl_stmt|;
name|u_char
name|window_x2
decl_stmt|;
block|}
name|type_u
struct|;
struct|struct
block|{
name|u_char
name|num_snd_x2
decl_stmt|;
name|u_char
name|num_rcv_x2
decl_stmt|;
block|}
name|type_i
struct|;
struct|struct
block|{
name|u_char
name|control
decl_stmt|;
name|u_char
name|num_rcv_x2
decl_stmt|;
block|}
name|type_s
struct|;
struct|struct
block|{
name|u_char
name|control
decl_stmt|;
name|u_char
name|org_code
index|[
literal|3
index|]
decl_stmt|;
name|u_short
name|ether_type
decl_stmt|;
block|}
name|type_snap
struct|;
block|}
name|llc_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|llc_control
value|llc_un.type_u.control
end_define

begin_define
define|#
directive|define
name|llc_fid
value|llc_un.type_u.format_id
end_define

begin_define
define|#
directive|define
name|llc_class
value|llc_un.type_u.class
end_define

begin_define
define|#
directive|define
name|llc_window
value|llc_un.type_u.window_x2
end_define

begin_define
define|#
directive|define
name|LLC_UI
value|0x3
end_define

begin_define
define|#
directive|define
name|LLC_UI_P
value|0x13
end_define

begin_define
define|#
directive|define
name|LLC_XID
value|0xaf
end_define

begin_define
define|#
directive|define
name|LLC_XID_P
value|0xbf
end_define

begin_define
define|#
directive|define
name|LLC_TEST
value|0xe3
end_define

begin_define
define|#
directive|define
name|LLC_TEST_P
value|0xf3
end_define

begin_define
define|#
directive|define
name|LLC_ISO_LSAP
value|0xfe
end_define

begin_define
define|#
directive|define
name|LLC_SNAP_LSAP
value|0xaa
end_define

end_unit

