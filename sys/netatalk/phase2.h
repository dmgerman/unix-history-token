begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_4
argument_list|)
end_if

begin_include
include|#
directive|include
file|<net/if_llc.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|llc_org_code
value|llc_un.type_snap.org_code
end_define

begin_define
define|#
directive|define
name|llc_ether_type
value|llc_un.type_snap.ether_type
end_define

begin_endif
endif|#
directive|endif
endif|__FreeBSD__
end_endif

begin_else
else|#
directive|else
else|ultrix BSD4_4
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_include
include|#
directive|include
file|<net/if_ieee802.h>
end_include

begin_endif
endif|#
directive|endif
endif|sun
end_endif

begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  *      @(#)if_llc.h	7.2 (Berkeley) 6/28/90  */
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
name|llc_org_code
value|llc_un.type_snap.org_code
end_define

begin_define
define|#
directive|define
name|llc_ether_type
value|llc_un.type_snap.ether_type
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

begin_endif
endif|#
directive|endif
endif|ultrix BSD4_4
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm032
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCPHASE1
value|_IOW(i, 100, struct ifreq)
end_define

begin_comment
comment|/* AppleTalk phase 1 */
end_comment

begin_define
define|#
directive|define
name|SIOCPHASE2
value|_IOW(i, 101, struct ifreq)
end_define

begin_comment
comment|/* AppleTalk phase 2 */
end_comment

begin_endif
endif|#
directive|endif
endif|sun ibm032
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_4
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCPHASE1
value|_IOW('i', 100, struct ifreq)
end_define

begin_comment
comment|/* AppleTalk phase 1 */
end_comment

begin_define
define|#
directive|define
name|SIOCPHASE2
value|_IOW('i', 101, struct ifreq)
end_define

begin_comment
comment|/* AppleTalk phase 2 */
end_comment

begin_endif
endif|#
directive|endif
endif|ultrix BSD4_4 _IBMR2
end_endif

end_unit

