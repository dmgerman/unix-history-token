begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cpu.h	4.1	81/02/19	*/
end_comment

begin_comment
comment|/*  * Cpu identification, from SID register.  */
end_comment

begin_union
union|union
name|cpusid
block|{
name|int
name|cpusid
decl_stmt|;
struct|struct
name|cpuany
block|{
name|u_int
label|:
literal|24
operator|,
name|cp_type
operator|:
literal|8
expr_stmt|;
block|}
name|cpuany
struct|;
struct|struct
name|cpu780
block|{
name|u_int
name|cp_sno
range|:
literal|12
decl_stmt|,
comment|/* serial number */
name|cp_plant
range|:
literal|3
decl_stmt|,
comment|/* plant number */
name|cp_eco
range|:
literal|9
decl_stmt|,
comment|/* eco level */
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_780 */
block|}
name|cpu780
struct|;
struct|struct
name|cpu750
block|{
name|u_int
name|cp_hrev
range|:
literal|8
decl_stmt|,
comment|/* hardware rev level */
name|cp_urev
range|:
literal|8
decl_stmt|,
comment|/* ucode rev level */
range|:
literal|8
decl_stmt|,
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_750 */
block|}
name|cpu750
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|VAX_780
value|1
end_define

begin_define
define|#
directive|define
name|VAX_750
value|2
end_define

begin_define
define|#
directive|define
name|VAX_MAX
value|2
end_define

begin_comment
comment|/*  * Per-cpu information for system.  */
end_comment

begin_struct
struct|struct
name|percpu
block|{
name|int
function_decl|(
modifier|*
name|pc_config
function_decl|)
parameter_list|()
function_decl|;
name|short
name|pc_cputype
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

