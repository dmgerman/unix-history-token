begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: netconfig.h,v 1.1 2000/06/02 22:57:54 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCONFIG_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|NETCONFIG
value|"/etc/netconfig"
end_define

begin_define
define|#
directive|define
name|NETPATH
value|"NETPATH"
end_define

begin_struct
struct|struct
name|netconfig
block|{
name|char
modifier|*
name|nc_netid
decl_stmt|;
comment|/* Network ID */
name|unsigned
name|long
name|nc_semantics
decl_stmt|;
comment|/* Semantics (see below) */
name|unsigned
name|long
name|nc_flag
decl_stmt|;
comment|/* Flags (see below) */
name|char
modifier|*
name|nc_protofmly
decl_stmt|;
comment|/* Protocol family */
name|char
modifier|*
name|nc_proto
decl_stmt|;
comment|/* Protocol name */
name|char
modifier|*
name|nc_device
decl_stmt|;
comment|/* Network device pathname */
name|unsigned
name|long
name|nc_nlookups
decl_stmt|;
comment|/* Number of directory lookup libs */
name|char
modifier|*
modifier|*
name|nc_lookups
decl_stmt|;
comment|/* Names of the libraries */
name|unsigned
name|long
name|nc_unused
index|[
literal|9
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|netconfig
modifier|*
modifier|*
name|nc_head
decl_stmt|;
name|struct
name|netconfig
modifier|*
modifier|*
name|nc_curr
decl_stmt|;
block|}
name|NCONF_HANDLE
typedef|;
end_typedef

begin_comment
comment|/*  * nc_semantics values  */
end_comment

begin_define
define|#
directive|define
name|NC_TPI_CLTS
value|1
end_define

begin_define
define|#
directive|define
name|NC_TPI_COTS
value|2
end_define

begin_define
define|#
directive|define
name|NC_TPI_COTS_ORD
value|3
end_define

begin_define
define|#
directive|define
name|NC_TPI_RAW
value|4
end_define

begin_comment
comment|/*  * nc_flag values  */
end_comment

begin_define
define|#
directive|define
name|NC_NOFLAG
value|0x00
end_define

begin_define
define|#
directive|define
name|NC_VISIBLE
value|0x01
end_define

begin_define
define|#
directive|define
name|NC_BROADCAST
value|0x02
end_define

begin_comment
comment|/*  * nc_protofmly values  */
end_comment

begin_define
define|#
directive|define
name|NC_NOPROTOFMLY
value|"-"
end_define

begin_define
define|#
directive|define
name|NC_LOOPBACK
value|"loopback"
end_define

begin_define
define|#
directive|define
name|NC_INET
value|"inet"
end_define

begin_define
define|#
directive|define
name|NC_INET6
value|"inet6"
end_define

begin_define
define|#
directive|define
name|NC_IMPLINK
value|"implink"
end_define

begin_define
define|#
directive|define
name|NC_PUP
value|"pup"
end_define

begin_define
define|#
directive|define
name|NC_CHAOS
value|"chaos"
end_define

begin_define
define|#
directive|define
name|NC_NS
value|"ns"
end_define

begin_define
define|#
directive|define
name|NC_NBS
value|"nbs"
end_define

begin_define
define|#
directive|define
name|NC_ECMA
value|"ecma"
end_define

begin_define
define|#
directive|define
name|NC_DATAKIT
value|"datakit"
end_define

begin_define
define|#
directive|define
name|NC_CCITT
value|"ccitt"
end_define

begin_define
define|#
directive|define
name|NC_SNA
value|"sna"
end_define

begin_define
define|#
directive|define
name|NC_DECNET
value|"decnet"
end_define

begin_define
define|#
directive|define
name|NC_DLI
value|"dli"
end_define

begin_define
define|#
directive|define
name|NC_LAT
value|"lat"
end_define

begin_define
define|#
directive|define
name|NC_HYLINK
value|"hylink"
end_define

begin_define
define|#
directive|define
name|NC_APPLETALK
value|"appletalk"
end_define

begin_define
define|#
directive|define
name|NC_NIT
value|"nit"
end_define

begin_define
define|#
directive|define
name|NC_IEEE802
value|"ieee802"
end_define

begin_define
define|#
directive|define
name|NC_OSI
value|"osi"
end_define

begin_define
define|#
directive|define
name|NC_X25
value|"x25"
end_define

begin_define
define|#
directive|define
name|NC_OSINET
value|"osinet"
end_define

begin_define
define|#
directive|define
name|NC_GOSIP
value|"gosip"
end_define

begin_comment
comment|/*  * nc_proto values  */
end_comment

begin_define
define|#
directive|define
name|NC_NOPROTO
value|"-"
end_define

begin_define
define|#
directive|define
name|NC_TCP
value|"tcp"
end_define

begin_define
define|#
directive|define
name|NC_UDP
value|"udp"
end_define

begin_define
define|#
directive|define
name|NC_ICMP
value|"icmp"
end_define

begin_function_decl
name|__BEGIN_DECLS
name|void
modifier|*
name|setnetconfig
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netconfig
modifier|*
name|getnetconfig
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netconfig
modifier|*
name|getnetconfigent
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freenetconfigent
parameter_list|(
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|endnetconfig
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|setnetpath
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netconfig
modifier|*
name|getnetpath
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|endnetpath
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nc_perror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nc_sperror
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETCONFIG_H_ */
end_comment

end_unit

