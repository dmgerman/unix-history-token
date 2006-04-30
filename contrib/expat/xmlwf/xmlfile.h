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

