begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mib.h - MIB realization */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/mib.h,v 7.11 91/02/22 09:43:35 mrose Interim $  *  * Contributed by NYSERNet Inc.  This work was partially supported by the  * U.S. Defense Advanced Research Projects Agency and the Rome Air Development  * Center of the U.S. Air Force Systems Command under contract number  * F30602-88-C-0016.  *  *  * $Log:	mib.h,v $  * Revision 7.11  91/02/22  09:43:35  mrose  * Interim 6.8  *   * Revision 7.10  91/01/12  21:22:56  mrose  * update  *   * Revision 7.9  91/01/11  15:34:31  mrose  * sets  *   * Revision 7.8  91/01/07  12:40:51  mrose  * update  *   * Revision 7.7  90/12/18  10:13:43  mrose  * update  *   * Revision 7.6  90/07/09  14:48:52  mrose  * sync  *   * Revision 7.5  90/05/14  13:28:17  mrose  * system  *   * Revision 7.4  90/05/13  16:18:13  mrose  * views  *   * Revision 7.3  90/02/27  18:49:47  mrose  * unix stuff  *   * Revision 7.2  90/02/17  10:38:21  mrose  * smux  *   * Revision 7.1  90/01/11  18:34:17  mrose  * real-sync  *   * Revision 7.0  89/11/23  22:23:13  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|"SNMP-types.h"
end_include

begin_include
include|#
directive|include
file|"objects.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_define
define|#
directive|define
name|generr
parameter_list|(
name|offset
parameter_list|)
value|((offset) == type_SNMP_PDUs_get__next__request \ 				    ? NOTOK : int_SNMP_error__status_genErr)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|sysDescr
value|"4BSD/ISODE SNMP"
end_define

begin_define
define|#
directive|define
name|sysObjectID
value|"fourBSD-isode.3"
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|nlist
name|nl
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|N_ARPTAB
value|0
end_define

begin_define
define|#
directive|define
name|N_ARPTAB_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|N_ICMPSTAT
value|2
end_define

begin_define
define|#
directive|define
name|N_IFNET
value|3
end_define

begin_define
define|#
directive|define
name|N_IPFORWARDING
value|4
end_define

begin_define
define|#
directive|define
name|N_IPSTAT
value|5
end_define

begin_define
define|#
directive|define
name|N_RTHASHSIZE
value|6
end_define

begin_define
define|#
directive|define
name|N_RTHOST
value|7
end_define

begin_define
define|#
directive|define
name|N_RTNET
value|8
end_define

begin_define
define|#
directive|define
name|N_TCB
value|9
end_define

begin_define
define|#
directive|define
name|N_TCPSTAT
value|10
end_define

begin_define
define|#
directive|define
name|N_UDB
value|11
end_define

begin_define
define|#
directive|define
name|N_UDPSTAT
value|12
end_define

begin_define
define|#
directive|define
name|N_RTSTAT
value|13
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_define
define|#
directive|define
name|N_RADIX_NODE_HEAD
value|14
end_define

begin_define
define|#
directive|define
name|N_ISO_SYSTYPE
value|15
end_define

begin_define
define|#
directive|define
name|N_CLNP_STAT
value|16
end_define

begin_define
define|#
directive|define
name|N_ESIS_STAT
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|init_mib
argument_list|()
decl_stmt|,
name|fin_mib
argument_list|()
decl_stmt|,
name|set_variable
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|getkmem
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|quantum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|my_boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OID
name|nullSpecific
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

