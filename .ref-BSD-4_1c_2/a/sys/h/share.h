begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	share.h	(Melb/Basser) 4.1	82/07/16	*/
end_comment

begin_comment
comment|/*  *	 MUSH Share scheduling parameters  */
end_comment

begin_struct
struct|struct
name|sh_consts
block|{
name|short
name|sc_fl
decl_stmt|;
comment|/* scheduling flags */
name|short
name|sc_maxnice
decl_stmt|;
comment|/* maximum nice cut-off */
name|float
name|sc_usagfactor
decl_stmt|;
comment|/* fudge factor */
name|float
name|sc_ratefactor
decl_stmt|;
comment|/* fudge factor */
name|long
name|sc_syscall
decl_stmt|;
comment|/* cost of system call */
name|long
name|sc_bio
decl_stmt|;
comment|/*   "  "  logical block i/o */
name|long
name|sc_tio
decl_stmt|;
comment|/*   "  "  terminal i/o */
name|long
name|sc_tic
decl_stmt|;
comment|/*   "  "  cpu tick */
name|long
name|sc_click
decl_stmt|;
comment|/*   "  "  memory */
name|long
name|sc_pgin
decl_stmt|;
comment|/*   "  "  hard page fault */
name|float
name|sc_usage
decl_stmt|;
comment|/* current share per usage */
name|float
name|sc_rate
decl_stmt|;
comment|/* current share per rate */
name|float
name|sc_usagk
decl_stmt|;
comment|/* usage decay rate */
name|long
name|sc_cost
decl_stmt|;
comment|/* total costs last period */
name|short
name|sc_users
decl_stmt|;
comment|/* number of real users */
name|short
name|sc_umin
decl_stmt|;
comment|/* minimum users for min share calc */
name|float
name|sc_ksmin
decl_stmt|;
comment|/* constant for min share */
name|short
name|sc_cpuwait
decl_stmt|;
comment|/* maximum period to wait for cpu */
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
name|callshare
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sh_consts
name|shconsts
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|shareflags
value|shconsts.sc_fl
end_define

begin_define
define|#
directive|define
name|Totusage
value|shconsts.sc_usage
end_define

begin_define
define|#
directive|define
name|Avrate
value|shconsts.sc_rate
end_define

begin_define
define|#
directive|define
name|maxnice
value|shconsts.sc_maxnice
end_define

begin_define
define|#
directive|define
name|USAGEFACTOR
value|shconsts.sc_usagfactor
end_define

begin_define
define|#
directive|define
name|RATEFACTOR
value|shconsts.sc_ratefactor
end_define

begin_define
define|#
directive|define
name|Usagek
value|shconsts.sc_usagk
end_define

begin_define
define|#
directive|define
name|Totusers
value|shconsts.sc_users
end_define

begin_define
define|#
directive|define
name|Totcost
value|shconsts.sc_cost
end_define

begin_define
define|#
directive|define
name|MINSHK
value|shconsts.sc_ksmin
end_define

begin_define
define|#
directive|define
name|MINUSERS
value|shconsts.sc_umin
end_define

begin_define
define|#
directive|define
name|CPUWAIT
value|shconsts.sc_cpuwait
end_define

begin_define
define|#
directive|define
name|NOSHARE
value|1
end_define

begin_define
define|#
directive|define
name|NONICE
value|2
end_define

begin_define
define|#
directive|define
name|MINNICE
value|0
end_define

begin_define
define|#
directive|define
name|BLOODYNICE
value|40
end_define

begin_define
define|#
directive|define
name|MINUSAGE
value|(1.0e6)
end_define

begin_define
define|#
directive|define
name|USAGEK
value|0.9999834
end_define

begin_comment
comment|/* decay usage 40% per day */
end_comment

begin_define
define|#
directive|define
name|CHARGE
parameter_list|(
name|cost
parameter_list|)
value|(u.u_quota->q_cost += shconsts.cost)
end_define

end_unit

