begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* clns.h - support for MIB realization of the experimental CLNS group */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/clns.h,v 7.4 91/02/22 09:43:00 mrose Interim $  *  * Contributed by NYSERNet Inc.  This work was partially supported by the  * U.S. Defense Advanced Research Projects Agency and the Rome Air Development  * Center of the U.S. Air Force Systems Command under contract number  * F30602-88-C-0016.  *  *  * $Log:	clns.h,v $  * Revision 7.4  91/02/22  09:43:00  mrose  * Interim 6.8  *   * Revision 7.3  90/12/18  10:13:17  mrose  * update  *   * Revision 7.2  89/12/19  16:18:22  mrose  * dgram  *   * Revision 7.1  89/12/01  10:42:14  mrose  * clts  *   * Revision 7.0  89/11/23  22:22:58  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD44
end_ifndef

begin_define
define|#
directive|define
name|AF_ISO
value|AF_NBS
end_define

begin_comment
comment|/* any value will do */
end_comment

begin_struct
struct|struct
name|iso_addr
block|{
name|u_char
name|isoa_len
decl_stmt|;
comment|/* length in octets */
name|char
name|isoa_genaddr
index|[
literal|20
index|]
decl_stmt|;
comment|/* general opaque address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sockaddr_iso
block|{
name|u_char
name|siso_len
decl_stmt|;
comment|/* length */
name|u_char
name|siso_family
decl_stmt|;
comment|/* address family */
name|u_char
name|siso_plen
decl_stmt|;
comment|/* psel length */
name|u_char
name|siso_slen
decl_stmt|;
comment|/* ssel length */
name|u_char
name|siso_tlen
decl_stmt|;
comment|/* tsel length */
name|struct
name|iso_addr
name|siso_addr
decl_stmt|;
comment|/* network address */
name|u_char
name|siso_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* space for gosip v2 sels */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|siso_nlen
value|siso_addr.isoa_len
end_define

begin_define
define|#
directive|define
name|siso_data
value|siso_addr.isoa_genaddr
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<netiso/iso.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

