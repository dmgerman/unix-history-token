begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|NAML$C_MAXRSS
end_ifdef

begin_define
define|#
directive|define
name|CC_RMS_NAMX
value|cc$rms_naml
end_define

begin_define
define|#
directive|define
name|FAB_NAMX
value|fab$l_naml
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML
parameter_list|(
name|fab
parameter_list|,
name|naml
parameter_list|)
value|naml
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_DNA
value|naml$l_long_defname
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_DNS
value|naml$l_long_defname_size
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_FNA
value|naml$l_long_filename
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_FNS
value|naml$l_long_filename_size
end_define

begin_define
define|#
directive|define
name|NAMX_ESA
value|naml$l_long_expand
end_define

begin_define
define|#
directive|define
name|NAMX_ESL
value|naml$l_long_expand_size
end_define

begin_define
define|#
directive|define
name|NAMX_ESS
value|naml$l_long_expand_alloc
end_define

begin_define
define|#
directive|define
name|NAMX_NOP
value|naml$b_nop
end_define

begin_define
define|#
directive|define
name|SET_NAMX_NO_SHORT_UPCASE
parameter_list|(
name|nam
parameter_list|)
value|nam.naml$v_no_short_upcase = 1
end_define

begin_if
if|#
directive|if
name|__INITIAL_POINTER_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|NAMX_DNA_FNA_SET
parameter_list|(
name|fab
parameter_list|)
value|fab.fab$l_dna = (__char_ptr32) -1; \    fab.fab$l_fna = (__char_ptr32) -1;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __INITIAL_POINTER_SIZE == 64 */
end_comment

begin_define
define|#
directive|define
name|NAMX_DNA_FNA_SET
parameter_list|(
name|fab
parameter_list|)
value|fab.fab$l_dna = (char *) -1; \    fab.fab$l_fna = (char *) -1;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INITIAL_POINTER_SIZE == 64 [else] */
end_comment

begin_define
define|#
directive|define
name|NAMX_MAXRSS
value|NAML$C_MAXRSS
end_define

begin_define
define|#
directive|define
name|NAMX_STRUCT
value|NAML
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* def NAML$C_MAXRSS */
end_comment

begin_define
define|#
directive|define
name|CC_RMS_NAMX
value|cc$rms_nam
end_define

begin_define
define|#
directive|define
name|FAB_NAMX
value|fab$l_nam
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML
parameter_list|(
name|fab
parameter_list|,
name|naml
parameter_list|)
value|fab
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_DNA
value|fab$l_dna
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_DNS
value|fab$b_dns
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_FNA
value|fab$l_fna
end_define

begin_define
define|#
directive|define
name|FAB_OR_NAML_FNS
value|fab$b_fns
end_define

begin_define
define|#
directive|define
name|NAMX_ESA
value|nam$l_esa
end_define

begin_define
define|#
directive|define
name|NAMX_ESL
value|nam$b_esl
end_define

begin_define
define|#
directive|define
name|NAMX_ESS
value|nam$b_ess
end_define

begin_define
define|#
directive|define
name|NAMX_NOP
value|nam$b_nop
end_define

begin_define
define|#
directive|define
name|NAMX_DNA_FNA_SET
parameter_list|(
name|fab
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NAMX_MAXRSS
value|NAM$C_MAXRSS
end_define

begin_define
define|#
directive|define
name|NAMX_STRUCT
value|NAM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NAM$M_NO_SHORT_UPCASE
end_ifdef

begin_define
define|#
directive|define
name|SET_NAMX_NO_SHORT_UPCASE
parameter_list|(
name|nam
parameter_list|)
value|naml.naml$v_no_short_upcase = 1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* def NAM$M_NO_SHORT_UPCASE */
end_comment

begin_define
define|#
directive|define
name|SET_NAMX_NO_SHORT_UPCASE
parameter_list|(
name|nam
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* def NAM$M_NO_SHORT_UPCASE [else] */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* def NAML$C_MAXRSS [else] */
end_comment

end_unit

