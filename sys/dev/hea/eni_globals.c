begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Global variable definitions  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni_stats.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Device unit table  */
end_comment

begin_decl_stmt
name|Eni_unit
modifier|*
name|eni_units
index|[
name|ENI_MAX_UNITS
index|]
init|=
block|{
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ATM Interface services  */
end_comment

begin_comment
comment|/*  * AAL5 service stack  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|stack_defn
name|eni_svaal5
init|=
block|{
name|NULL
block|,
name|SAP_CPCS_AAL5
block|,
name|SDF_TERM
block|,
name|atm_dev_inst
block|,
name|atm_dev_lower
block|,
name|NULL
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Efficient hardware doesn't support AAL3/4. Don't define  * an AAL3/4 stack.  */
end_comment

begin_comment
comment|/*  * AAL0 service stack  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|stack_defn
name|eni_svaal0
init|=
block|{
operator|&
name|eni_svaal5
block|,
name|SAP_ATM
block|,
name|SDF_TERM
block|,
name|atm_dev_inst
block|,
name|atm_dev_lower
block|,
name|NULL
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stack_defn
modifier|*
name|eni_services
init|=
operator|&
name|eni_svaal0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Storage pools  */
end_comment

begin_decl_stmt
name|struct
name|sp_info
name|eni_nif_pool
init|=
block|{
literal|"eni nif pool"
block|,
comment|/* si_name */
sizeof|sizeof
argument_list|(
expr|struct
name|atm_nif
argument_list|)
block|,
comment|/* si_blksiz */
literal|5
block|,
comment|/* si_blkcnt */
literal|52
comment|/* si_maxallow */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sp_info
name|eni_vcc_pool
init|=
block|{
literal|"eni vcc pool"
block|,
comment|/* si_name */
sizeof|sizeof
argument_list|(
name|Eni_vcc
argument_list|)
block|,
comment|/* si_blksiz */
literal|10
block|,
comment|/* si_blkcnt */
literal|100
comment|/* si_maxallow */
block|}
decl_stmt|;
end_decl_stmt

end_unit

