begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__TRACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__TRACE_H__
end_define

begin_decl_stmt
specifier|extern
name|void
name|__m_install_record
name|proto
argument_list|(
operator|(
name|univptr_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__m_delete_record
name|proto
argument_list|(
operator|(
name|univptr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RECORD_FILE_AND_LINE
parameter_list|(
name|addr
parameter_list|,
name|fname
parameter_list|,
name|linenum
parameter_list|)
define|\
value|if (_malloc_leaktrace) { \ 		(void) sprintf(_malloc_statsbuf, "%s:%d:", fname, linenum); \ 		__m_install_record(addr, _malloc_statsbuf); \ 	} else \ 		_malloc_leaktrace += 0
end_define

begin_define
define|#
directive|define
name|DELETE_RECORD
parameter_list|(
name|addr
parameter_list|)
define|\
value|if (_malloc_leaktrace) \ 		__m_delete_record(addr); \ 	else \ 		_malloc_leaktrace += 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TRACE_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

