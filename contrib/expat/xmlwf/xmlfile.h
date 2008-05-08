begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd    See the file COPYING for copying permission. */
end_comment

begin_define
define|#
directive|define
name|XML_MAP_FILE
value|01
end_define

begin_define
define|#
directive|define
name|XML_EXTERNAL_ENTITIES
value|02
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XML_LARGE_SIZE
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XML_USE_MSC_EXTENSIONS
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1400
end_if

begin_define
define|#
directive|define
name|XML_FMT_INT_MOD
value|"I64"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XML_FMT_INT_MOD
value|"ll"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XML_FMT_INT_MOD
value|"l"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|XML_ProcessFile
parameter_list|(
name|XML_Parser
name|parser
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|filename
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
end_function_decl

end_unit

