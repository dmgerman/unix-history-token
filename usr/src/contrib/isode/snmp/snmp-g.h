begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* snmp-g.h - SNMP group */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/snmp-g.h,v 7.2 91/02/22 09:44:06 mrose Interim $  *  *  * $Log:	snmp-g.h,v $  * Revision 7.2  91/02/22  09:44:06  mrose  * Interim 6.8  *   * Revision 7.1  91/01/11  15:35:07  mrose  * sets  *   * Revision 7.0  90/12/17  22:07:57  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_struct
struct|struct
name|snmpstat
block|{
name|integer
name|s_inpkts
decl_stmt|;
name|integer
name|s_outpkts
decl_stmt|;
name|integer
name|s_badversions
decl_stmt|;
name|integer
name|s_badcommunitynames
decl_stmt|;
name|integer
name|s_badcommunityuses
decl_stmt|;
name|integer
name|s_asnparseerrs
decl_stmt|;
name|integer
name|s_totalreqvars
decl_stmt|;
name|integer
name|s_totalsetvars
decl_stmt|;
name|integer
name|s_ingetrequests
decl_stmt|;
name|integer
name|s_ingetnexts
decl_stmt|;
name|integer
name|s_insetrequests
decl_stmt|;
name|integer
name|s_ingetresponses
decl_stmt|;
name|integer
name|s_intraps
decl_stmt|;
name|integer
name|s_outgetresponses
decl_stmt|;
name|integer
name|s_outtraps
decl_stmt|;
name|integer
name|s_toobigs
decl_stmt|;
name|integer
name|s_nosuchnames
decl_stmt|;
name|integer
name|s_badvalues
decl_stmt|;
name|integer
name|s_readonlys
decl_stmt|;
name|integer
name|s_generrs
decl_stmt|;
name|integer
name|s_enableauthentraps
decl_stmt|;
define|#
directive|define
name|TRAPS_ENABLED
value|1
comment|/* snmpEnableAuthenTraps */
define|#
directive|define
name|TRAPS_DISABLED
value|2
comment|/*   .. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|snmpstat
name|snmpstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|unix_netstat
decl_stmt|;
end_decl_stmt

end_unit

