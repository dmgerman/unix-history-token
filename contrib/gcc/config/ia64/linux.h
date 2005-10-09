begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ia64-linux target.  */
end_comment

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (IA-64) Linux");
end_define

begin_comment
comment|/* This is for -profile to use -lc_p instead of -lc.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{profile:-p} %{G*}"
end_define

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {						\ 	LINUX_TARGET_OS_CPP_BUILTINS();		\ 	builtin_define("_LONGLONG");		\ } while (0)
end_define

begin_comment
comment|/* Need to override linux.h STARTFILE_SPEC, since it has crtbeginT.o in.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_PIE
end_ifdef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: %{pg|p|profile:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}}\    crti.o%s %{shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: %{pg|p|profile:gcrt1.o%s;:crt1.o%s}}\    crti.o%s %{shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Similar to standard Linux, but adding -ffast-math support.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    %{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
end_define

begin_comment
comment|/* Define this for shared library support because it isn't in the main    linux.h file.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\   %{shared:-shared} \   %{!shared: \     %{!static: \       %{rdynamic:-export-dynamic} \       %{!dynamic-linker:-dynamic-linker /lib/ld-linux-ia64.so.2}} \       %{static:-static}}"
end_define

begin_define
define|#
directive|define
name|JMP_BUF_SIZE
value|76
end_define

begin_comment
comment|/* Override linux.h LINK_EH_SPEC definition.    Signalize that because we have fde-glibc, we don't need all C shared libs    linked against -lgcc_s.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_EH_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|""
end_define

begin_comment
comment|/* Do code reading to identify a signal frame, and set the frame    state data appropriately.  See unwind-dw2.c for the structs.  */
end_comment

begin_comment
comment|/* This works only for glibc-2.3 and later, because sigcontext is different    in glibc-2.2.4.  */
end_comment

begin_if
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>=
literal|3
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_define
define|#
directive|define
name|IA64_GATE_AREA_START
value|0xa000000000000100LL
end_define

begin_define
define|#
directive|define
name|IA64_GATE_AREA_END
value|0xa000000000030000LL
end_define

begin_define
define|#
directive|define
name|MD_FALLBACK_FRAME_STATE_FOR
parameter_list|(
name|CONTEXT
parameter_list|,
name|FS
parameter_list|,
name|SUCCESS
parameter_list|)
define|\
value|if ((CONTEXT)->rp>= IA64_GATE_AREA_START				\&& (CONTEXT)->rp< IA64_GATE_AREA_END)				\     {									\       struct sigframe {							\ 	char scratch[16];						\ 	unsigned long sig_number;					\ 	struct siginfo *info;						\ 	struct sigcontext *sc;						\       } *frame_ = (struct sigframe *)(CONTEXT)->psp;			\       struct sigcontext *sc_ = frame_->sc;				\ 									\
comment|/* Restore scratch registers in case the unwinder needs to	\ 	 refer to a value stored in one of them.  */
value|\       {									\ 	int i_;								\ 									\ 	for (i_ = 2; i_< 4; i_++)					\ 	  (CONTEXT)->ireg[i_ - 2].loc =&sc_->sc_gr[i_];		\ 	for (i_ = 8; i_< 12; i_++)					\ 	  (CONTEXT)->ireg[i_ - 2].loc =&sc_->sc_gr[i_];		\ 	for (i_ = 14; i_< 32; i_++)					\ 	  (CONTEXT)->ireg[i_ - 2].loc =&sc_->sc_gr[i_];		\       }									\ 	  								\       (CONTEXT)->fpsr_loc =&(sc_->sc_ar_fpsr);				\       (CONTEXT)->pfs_loc =&(sc_->sc_ar_pfs);				\       (CONTEXT)->lc_loc =&(sc_->sc_ar_lc);				\       (CONTEXT)->unat_loc =&(sc_->sc_ar_unat);				\       (CONTEXT)->br_loc[0] =&(sc_->sc_br[0]);				\       (CONTEXT)->br_loc[6] =&(sc_->sc_br[6]);				\       (CONTEXT)->br_loc[7] =&(sc_->sc_br[7]);				\       (CONTEXT)->pr = sc_->sc_pr;					\       (CONTEXT)->psp = sc_->sc_gr[12];					\       (CONTEXT)->gp = sc_->sc_gr[1];					\
comment|/* Signal frame doesn't have an associated reg. stack frame 	\          other than what we adjust for below.	  */
value|\       (FS) -> no_reg_stack_frame = 1;					\ 									\       if (sc_->sc_rbs_base)						\ 	{								\
comment|/* Need to switch from alternate register backing store.  */
value|\ 	  long ndirty, loadrs = sc_->sc_loadrs>> 16;			\ 	  unsigned long alt_bspstore = (CONTEXT)->bsp - loadrs;		\ 	  unsigned long bspstore;					\ 	  unsigned long *ar_bsp = (unsigned long *)(sc_->sc_ar_bsp);	\ 									\ 	  ndirty = ia64_rse_num_regs ((unsigned long *) alt_bspstore,	\ 				      (unsigned long *) (CONTEXT)->bsp);\ 	  bspstore = (unsigned long)					\ 		     ia64_rse_skip_regs (ar_bsp, -ndirty);		\ 	  ia64_copy_rbs ((CONTEXT), bspstore, alt_bspstore, loadrs,	\ 			 sc_->sc_ar_rnat);				\ 	}								\ 									\
comment|/* Don't touch the branch registers o.t. b0, b6 and b7.		\ 	 The kernel doesn't pass the preserved branch registers		\ 	 in the sigcontext but leaves them intact, so there's no	\ 	 need to do anything with them here.  */
value|\       {									\ 	unsigned long sof = sc_->sc_cfm& 0x7f;				\ 	(CONTEXT)->bsp = (unsigned long)				\ 	  ia64_rse_skip_regs ((unsigned long *)(sc_->sc_ar_bsp), -sof); \       }									\ 									\       (FS)->curr.reg[UNW_REG_RP].where = UNW_WHERE_SPREL;		\       (FS)->curr.reg[UNW_REG_RP].val 					\ 	= (unsigned long)&(sc_->sc_ip) - (CONTEXT)->psp;		\       (FS)->curr.reg[UNW_REG_RP].when = -1;				\ 									\       goto SUCCESS;							\     }
end_define

begin_define
define|#
directive|define
name|MD_HANDLE_UNWABI
parameter_list|(
name|CONTEXT
parameter_list|,
name|FS
parameter_list|)
define|\
value|if ((FS)->unwabi == ((3<< 8) | 's')					\       || (FS)->unwabi == ((0<< 8) | 's'))				\     {									\       struct sigframe {							\ 	char scratch[16];						\ 	unsigned long sig_number;					\ 	struct siginfo *info;						\ 	struct sigcontext *sc;						\       } *frame_ = (struct sigframe *)(CONTEXT)->psp;			\       struct sigcontext *sc_ = frame_->sc;				\ 									\
comment|/* Restore scratch registers in case the unwinder needs to	\ 	 refer to a value stored in one of them.  */
value|\       {									\ 	int i_;								\ 									\ 	for (i_ = 2; i_< 4; i_++)					\ 	  (CONTEXT)->ireg[i_ - 2].loc =&sc_->sc_gr[i_];		\ 	for (i_ = 8; i_< 12; i_++)					\ 	  (CONTEXT)->ireg[i_ - 2].loc =&sc_->sc_gr[i_];		\ 	for (i_ = 14; i_< 32; i_++)					\ 	  (CONTEXT)->ireg[i_ - 2].loc =&sc_->sc_gr[i_];		\       }									\ 	  								\       (CONTEXT)->pfs_loc =&(sc_->sc_ar_pfs);				\       (CONTEXT)->lc_loc =&(sc_->sc_ar_lc);				\       (CONTEXT)->unat_loc =&(sc_->sc_ar_unat);				\       (CONTEXT)->br_loc[0] =&(sc_->sc_br[0]);				\       (CONTEXT)->br_loc[6] =&(sc_->sc_br[6]);				\       (CONTEXT)->br_loc[7] =&(sc_->sc_br[7]);				\       (CONTEXT)->pr = sc_->sc_pr;					\       (CONTEXT)->gp = sc_->sc_gr[1];					\
comment|/* Signal frame doesn't have an associated reg. stack frame 	\          other than what we adjust for below.	  */
value|\       (FS) -> no_reg_stack_frame = 1;					\ 									\       if (sc_->sc_rbs_base)						\ 	{								\
comment|/* Need to switch from alternate register backing store.  */
value|\ 	  long ndirty, loadrs = sc_->sc_loadrs>> 16;			\ 	  unsigned long alt_bspstore = (CONTEXT)->bsp - loadrs;		\ 	  unsigned long bspstore;					\ 	  unsigned long *ar_bsp = (unsigned long *)(sc_->sc_ar_bsp);	\ 									\ 	  ndirty = ia64_rse_num_regs ((unsigned long *) alt_bspstore,	\ 				      (unsigned long *) (CONTEXT)->bsp);\ 	  bspstore = (unsigned long)					\ 		     ia64_rse_skip_regs (ar_bsp, -ndirty);		\ 	  ia64_copy_rbs ((CONTEXT), bspstore, alt_bspstore, loadrs,	\ 			 sc_->sc_ar_rnat);				\ 	}								\ 									\
comment|/* Don't touch the branch registers o.t. b0, b6 and b7.		\ 	 The kernel doesn't pass the preserved branch registers		\ 	 in the sigcontext but leaves them intact, so there's no	\ 	 need to do anything with them here.  */
value|\       {									\ 	unsigned long sof = sc_->sc_cfm& 0x7f;				\ 	(CONTEXT)->bsp = (unsigned long)				\ 	  ia64_rse_skip_regs ((unsigned long *)(sc_->sc_ar_bsp), -sof); \       }									\ 									\
comment|/* pfs_loc already set above.  Without this pfs_loc would point	\ 	 incorrectly to sc_cfm instead of sc_ar_pfs.  */
value|\       (FS)->curr.reg[UNW_REG_PFS].where = UNW_WHERE_NONE;		\     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_LIBGCC2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* glibc-2.3 or better */
end_comment

end_unit

