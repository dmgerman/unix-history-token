begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* interfaces.h - support for MIB realization of the Interfaces group */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/interfaces.h,v 7.6 91/02/22 09:43:26 mrose Interim $  *  * Contributed by NYSERNet Inc.  This work was partially supported by the  * U.S. Defense Advanced Research Projects Agency and the Rome Air Development  * Center of the U.S. Air Force Systems Command under contract number  * F30602-88-C-0016.  *  *  * $Log:	interfaces.h,v $  * Revision 7.6  91/02/22  09:43:26  mrose  * Interim 6.8  *   * Revision 7.5  90/12/18  10:13:34  mrose  * update  *   * Revision 7.4  90/10/23  20:36:22  mrose  * update  *   * Revision 7.3  90/10/17  14:33:24  mrose  * update  *   * Revision 7.2  90/03/24  10:54:06  mrose  * update  *   * Revision 7.1  90/01/11  18:34:08  mrose  * real-sync  *   * Revision 7.0  89/11/23  22:23:06  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"internet.h"
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_comment
comment|/* to get struct arpcom */
end_comment

begin_include
include|#
directive|include
file|"clns.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ifNumber
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|interface
block|{
name|int
name|ifn_index
decl_stmt|;
comment|/* 1..ifNumber */
name|int
name|ifn_indexmask
decl_stmt|;
comment|/* 1<< (index - 1) */
name|int
name|ifn_ready
decl_stmt|;
comment|/* has an address associated with it */
name|struct
name|arpcom
name|ifn_interface
decl_stmt|;
comment|/* ifnet+physaddr */
name|unsigned
name|long
name|ifn_offset
decl_stmt|;
comment|/* where in kmem */
name|char
name|ifn_descr
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* e.g., "lo0" */
name|int
name|ifn_type
decl_stmt|;
comment|/* ifType */
name|u_long
name|ifn_speed
decl_stmt|;
comment|/* ifSpeed */
name|int
name|ifn_admin
decl_stmt|;
comment|/* ifAdminStatus */
name|struct
name|interface
modifier|*
name|ifn_next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|ifs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|set_interface
argument_list|()
decl_stmt|,
name|sort_interface
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_union
union|union
name|sockaddr_un
block|{
comment|/* 'cause sizeof (struct sockaddr_iso) == 32 */
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|un_in
decl_stmt|;
ifdef|#
directive|ifdef
name|BSD44
name|struct
name|sockaddr_iso
name|un_iso
decl_stmt|;
endif|#
directive|endif
block|}
union|;
end_union

begin_struct
struct|struct
name|address
block|{
define|#
directive|define
name|ADR_SIZE
value|(20 + 1 + 1)
comment|/* object instance */
name|unsigned
name|int
name|adr_instance
index|[
name|ADR_SIZE
index|]
decl_stmt|;
name|int
name|adr_insize
decl_stmt|;
name|union
name|sockaddr_un
name|adr_address
decl_stmt|;
comment|/* address */
name|union
name|sockaddr_un
name|adr_broadaddr
decl_stmt|;
comment|/*   broadcast, only if AF_INET */
name|union
name|sockaddr_un
name|adr_netmask
decl_stmt|;
comment|/*   network mask */
name|int
name|adr_indexmask
decl_stmt|;
comment|/* mask of interfaces with address */
name|struct
name|address
modifier|*
name|adr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|address
modifier|*
name|afs_inet
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|address
modifier|*
name|afs_iso
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|address
modifier|*
name|find_address
argument_list|()
decl_stmt|,
modifier|*
name|get_addrent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD44
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD43_Tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|RT
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEW_AT
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|NEW_AT
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

