begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   $Log:	rdp_fsm.c,v $  * Revision 2.1  84/11/02  10:12:44  walsh  * Fixed to include RCS comments in checked out source.  *   *  * description:  * Transition table for RDP finite state machine.  *   * revision 1.5          * date: 84/07/22 19:44:39;  author: walsh;  state: Exp;  lines added/del: 2/1  * Added a state transition function rdp_closew_rcv() to compensate for  * socket code's dropping of system priority level for a brief period of time.  *   * revision 1.4          * date: 84/07/18 18:50:34;  author: walsh;  state: Exp;  lines added/del: 2/1  * Added provision for sending of NULL messages.  These are sent on an idle  * connection to determine that the other side still exists.  *   * revision 1.3          * date: 84/07/09 14:17:34;  author: walsh;  state: Exp;  lines added/del: 2/1  * Added ACK-delay timer to debugging printf arrays.  *   * revision 1.2          * date: 84/07/06 09:49:07;  author: root;  state: Exp;  lines added/del: 1/1  * This version seems to run bug-free.  *   * revision 1.1          * date: 84/06/26 14:16:59;  author: walsh;  state: Exp;    * Initial revision  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RDP
end_ifdef

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/kernel.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"../h/socket.h"
end_include

begin_include
include|#
directive|include
file|"../h/socketvar.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"../bbnnet/in.h"
end_include

begin_include
include|#
directive|include
file|"../bbnnet/in_var.h"
end_include

begin_include
include|#
directive|include
file|"../bbnnet/net.h"
end_include

begin_include
include|#
directive|include
file|"../bbnnet/in_pcb.h"
end_include

begin_include
include|#
directive|include
file|"../bbnnet/ip.h"
end_include

begin_include
include|#
directive|include
file|"../bbnnet/rdp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RDPDEBUG
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|rdpstates
index|[
name|RDP_NSTATES
index|]
init|=
block|{
literal|"RDP_sSAME"
block|,
literal|"RDP_sUNOPENED"
block|,
literal|"RDP_sLISTEN"
block|,
literal|"RDP_sSYNSENT"
block|,
literal|"RDP_sLSYNRCVD"
block|,
literal|"RDP_sSYNRCVD"
block|,
literal|"RDP_sESTAB"
block|,
literal|"RDP_sCLOSEWAIT"
block|,
literal|"RDP_sCLOSED"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rdpinputs
index|[
name|RDP_NINPUTS
index|]
init|=
block|{
literal|"RDP_iCONNECT"
block|,
literal|"RDP_iLISTEN"
block|,
literal|"RDP_iNETR"
block|,
literal|"RDP_iUCLOSE"
block|,
literal|"RDP_iTIMER"
block|,
literal|"RDP_iRCV"
block|,
literal|"RDP_iSEND"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rdptimers
index|[
name|RDP_NTIMERS
index|]
init|=
block|{
literal|"RDP_tCLOSEWAIT"
block|,
literal|"RDP_tRTTL"
block|,
literal|"RDP_tRXMIT"
block|,
literal|"RDP_tACKDELAY"
block|,
literal|"RDP_tNULL"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|rdp_unop_connect
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sUNOPENED x RDP_iCONNECT */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_unop_listen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sUNOPENED x RDP_iLISTEN */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_unop_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sUNOPENED x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_unop_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sUNOPENED x RDP_iUCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_lis_listen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sLISTEN x RDP_iLISTEN */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_lis_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sLISTEN x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_lis_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sLISTEN x RDP_iCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_synsent_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sSYNSENT x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_synsent_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sSYNSENT x RDP_iUCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_synsent_timer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sSYNSENT x RDP_iTIMER */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_lsynrcvd_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sLSYNRCVD x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_lsynrcvd_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sLSYNRCVD x RDP_iUCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_lsynrcvd_timer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sLSYNRCVD x RDP_iTIMER */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_synrcvd_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sSYNRCVD x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_synrcvd_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sSYNRCVD x RDP_iUCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_synrcvd_timer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sSYNRCVD x RDP_iTIMER */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_estab_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sESTAB x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_estab_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sESTAB x RDP_iUCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_estab_timer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sESTAB x RDP_iTIMER */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_estab_rcv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sESTAB x RDP_iRCV */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_estab_send
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sESTAB x RDP_iSEND */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_closew_netr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sCLOSEWAIT x RDP_iNETR */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_closew_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sCLOSEWAIT x RDP_iUCLOSE */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_closew_timer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sCLOSEWAIT x RDP_iTIMER */
end_comment

begin_function_decl
specifier|extern
name|int
name|rdp_closew_rcv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RDP_sCLOSEWAIT x RDP_iRCV */
end_comment

begin_define
define|#
directive|define
name|illegal
value|0
end_define

begin_function_decl
name|int
function_decl|(
modifier|*
name|rdp_action_table
index|[
name|RDP_NSTATES
index|]
index|[
name|RDP_NINPUTS
index|]
function_decl|)
parameter_list|()
init|=
block|{
block|{
name|illegal
operator|,
comment|/* to avoid off-by-1 error because SAME is 0 */
function_decl|illegal
operator|,
function_decl|illegal
operator|,
function_decl|illegal
operator|,
function_decl|illegal
operator|,
function_decl|illegal
operator|,
function_decl|illegal
end_function_decl

begin_block
unit|}     ,
block|{
name|rdp_unop_connect
operator|,
name|rdp_unop_listen
operator|,
name|rdp_unop_netr
operator|,
name|rdp_unop_close
operator|,
name|illegal
operator|,
name|illegal
operator|,
name|illegal
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|illegal
operator|,
name|rdp_lis_listen
operator|,
name|rdp_lis_netr
operator|,
name|rdp_lis_close
operator|,
name|illegal
operator|,
name|illegal
operator|,
name|illegal
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|illegal
operator|,
name|illegal
operator|,
name|rdp_synsent_netr
operator|,
name|rdp_synsent_close
operator|,
name|rdp_synsent_timer
operator|,
name|illegal
operator|,
name|illegal
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|illegal
operator|,
name|illegal
operator|,
name|rdp_lsynrcvd_netr
operator|,
name|rdp_lsynrcvd_close
operator|,
name|rdp_lsynrcvd_timer
operator|,
name|illegal
operator|,
name|illegal
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|illegal
operator|,
name|illegal
operator|,
name|rdp_synrcvd_netr
operator|,
name|rdp_synrcvd_close
operator|,
name|rdp_synrcvd_timer
operator|,
name|illegal
operator|,
name|illegal
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|illegal
operator|,
name|illegal
operator|,
name|rdp_estab_netr
operator|,
name|rdp_estab_close
operator|,
name|rdp_estab_timer
operator|,
name|rdp_estab_rcv
operator|,
name|rdp_estab_send
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|illegal
operator|,
name|illegal
operator|,
name|rdp_closew_netr
operator|,
name|rdp_closew_close
operator|,
name|rdp_closew_timer
operator|,
name|rdp_closew_rcv
operator|,
name|illegal
block|}
end_block

begin_endif
unit|} ;
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

