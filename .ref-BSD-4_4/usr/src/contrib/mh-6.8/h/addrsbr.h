begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* addrsbr.h - definitions for the address parsing system */
end_comment

begin_define
define|#
directive|define
name|AD_HOST
value|1
end_define

begin_comment
comment|/* getm(): lookup official hostname */
end_comment

begin_define
define|#
directive|define
name|AD_NHST
value|0
end_define

begin_comment
comment|/* getm(): do not lookup official name */
end_comment

begin_define
define|#
directive|define
name|AD_NAME
value|AD_NHST
end_define

begin_comment
comment|/* AD_HOST is TOO slow */
end_comment

begin_struct
struct|struct
name|mailname
block|{
name|struct
name|mailname
modifier|*
name|m_next
decl_stmt|;
name|char
modifier|*
name|m_text
decl_stmt|,
modifier|*
name|m_pers
decl_stmt|,
modifier|*
name|m_mbox
decl_stmt|,
modifier|*
name|m_host
decl_stmt|,
modifier|*
name|m_path
decl_stmt|;
name|int
name|m_type
decl_stmt|;
define|#
directive|define
name|UUCPHOST
value|(-1)
define|#
directive|define
name|LOCALHOST
value|0
define|#
directive|define
name|NETHOST
value|1
define|#
directive|define
name|BADHOST
value|2
name|char
name|m_nohost
decl_stmt|;
name|char
name|m_bcc
decl_stmt|;
name|int
name|m_ingrp
decl_stmt|;
name|char
modifier|*
name|m_gname
decl_stmt|;
name|char
modifier|*
name|m_note
decl_stmt|;
ifdef|#
directive|ifdef
name|MHMTS
name|char
modifier|*
name|m_aka
decl_stmt|;
endif|#
directive|endif
comment|/* MHMTS */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|mnfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ismymbox
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|getname
argument_list|()
decl_stmt|,
modifier|*
name|adrsprintf
argument_list|()
decl_stmt|,
modifier|*
name|auxformat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|mailname
modifier|*
name|getm
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|adrformat
parameter_list|(
name|m
parameter_list|)
value|auxformat ((m), 1)
end_define

begin_decl_stmt
name|char
modifier|*
name|LocalName
argument_list|()
decl_stmt|,
modifier|*
name|SystemName
argument_list|()
decl_stmt|,
modifier|*
name|UucpChan
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|OfficialName
parameter_list|()
function_decl|;
end_function_decl

end_unit

