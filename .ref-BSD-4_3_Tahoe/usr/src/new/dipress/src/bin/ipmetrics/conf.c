begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986 Xerox Corp.  *  * configure the system here.  * The following table defines how each composition system that ipmetrics  * can generate for is called.  *  * ADDING A NEW COMPOSITION SYSTEM:  *	fill out a line somewhere detailing the new system.  *  * HISTORY  * 08-Sep-86  Lee Moore (lee) at Xerox Webster Research Center  *	Added entry for old troff.  *  * 18-Aug-86  Lee Moore (lee) at Xerox Webster Research Center  *	Created.  *  *  */
end_comment

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_decl_stmt
specifier|extern
name|int
name|PerTroffFont
argument_list|()
decl_stmt|,
name|CleanUpTroff
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PerOTroffFont
argument_list|()
decl_stmt|,
name|CleanUpOTroff
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PerTeXFont
argument_list|()
decl_stmt|,
name|CleanUpTeX
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|InitTOC
argument_list|()
decl_stmt|,
name|PerTOCFont
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PerGenericFont
argument_list|()
decl_stmt|,
name|CleanUpGeneric
argument_list|()
decl_stmt|;
end_decl_stmt

begin_macro
name|null
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_decl_stmt
name|struct
name|CompositionSwitch
name|CompositionSwitch
index|[]
init|=
block|{
literal|"troff"
block|,
name|TRUE
block|,
name|null
block|,
name|PerTroffFont
block|,
name|CleanUpTroff
block|,
literal|"otroff"
block|,
name|TRUE
block|,
name|null
block|,
name|PerOTroffFont
block|,
name|CleanUpOTroff
block|,
literal|"TeX"
block|,
name|TRUE
block|,
name|null
block|,
name|PerTeXFont
block|,
name|CleanUpTeX
block|,
literal|"toc"
block|,
name|FALSE
block|,
name|InitTOC
block|,
name|PerTOCFont
block|,
name|null
block|,
literal|"generic"
block|,
name|TRUE
block|,
name|null
block|,
name|PerGenericFont
block|,
name|CleanUpGeneric
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

