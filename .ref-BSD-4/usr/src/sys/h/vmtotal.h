begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmtotal.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/* systemwide totals computed every five seconds */
end_comment

begin_struct
struct|struct
name|vmtotal
block|{
name|short
name|t_rq
decl_stmt|;
comment|/* length of the run queue */
name|short
name|t_dw
decl_stmt|;
comment|/* jobs in ``disk wait'' (neg priority) */
name|short
name|t_pw
decl_stmt|;
comment|/* jobs in page wait */
name|short
name|t_sl
decl_stmt|;
comment|/* jobs sleeping in core */
name|short
name|t_sw
decl_stmt|;
comment|/* swapped out runnable/short block jobs */
name|int
name|t_vm
decl_stmt|;
comment|/* total virtual memory */
name|int
name|t_avm
decl_stmt|;
comment|/* active virtual memory */
name|short
name|t_rm
decl_stmt|;
comment|/* total real memory in use */
name|short
name|t_arm
decl_stmt|;
comment|/* active real memory */
name|int
name|t_vmtxt
decl_stmt|;
comment|/* virtual memory used by text */
name|int
name|t_avmtxt
decl_stmt|;
comment|/* active virtual memory used by text */
name|short
name|t_rmtxt
decl_stmt|;
comment|/* real memory used by text */
name|short
name|t_armtxt
decl_stmt|;
comment|/* active real memory used by text */
name|short
name|t_free
decl_stmt|;
comment|/* free memory pages */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|vmtotal
name|total
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

