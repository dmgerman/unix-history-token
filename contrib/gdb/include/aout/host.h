begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters about the a.out format, based on the host system on which    the program is compiled.  */
end_comment

begin_comment
comment|/* Address of data segment in memory after it is loaded.    It is up to you to define SEGMENT_SIZE    on machines not listed here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEGMENT_SIZE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hp300
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|page_size
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sony
end_ifdef

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sony.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|is68k
end_ifdef

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x20000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|m68k
argument_list|)
operator|&&
name|defined
argument_list|(
name|PORTAR
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x400
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(SEGMENT_SIZE)*/
end_comment

end_unit

