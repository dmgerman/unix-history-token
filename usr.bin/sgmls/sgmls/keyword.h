begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* KEYWORD.H: Definitions for markup declaration keyword processing. */
end_comment

begin_comment
comment|/* Default value types for attribute definition list declaration. */
end_comment

begin_define
define|#
directive|define
name|DNULL
value|1
end_define

begin_comment
comment|/* Default value: implied attribute. */
end_comment

begin_define
define|#
directive|define
name|DREQ
value|2
end_define

begin_comment
comment|/* Default value: required attribute. */
end_comment

begin_define
define|#
directive|define
name|DCURR
value|3
end_define

begin_comment
comment|/* Default value: current attribute. */
end_comment

begin_define
define|#
directive|define
name|DCONR
value|4
end_define

begin_comment
comment|/* Default value: content reference attribute. */
end_comment

begin_define
define|#
directive|define
name|DFIXED
value|5
end_define

begin_comment
comment|/* Default value: fixed attribute. */
end_comment

begin_comment
comment|/* External identifier types for entity and notation declarations. */
end_comment

begin_define
define|#
directive|define
name|EDSYSTEM
value|1
end_define

begin_comment
comment|/* SYSTEM (but not PUBLIC) identifier specified.*/
end_comment

begin_define
define|#
directive|define
name|EDPUBLIC
value|2
end_define

begin_comment
comment|/* PUBLIC (but not SYSTEM) identifier specified.*/
end_comment

begin_define
define|#
directive|define
name|EDBOTH
value|3
end_define

begin_comment
comment|/* PUBLIC and also SYSTEM identifiers specified.*/
end_comment

begin_comment
comment|/* Marked section keywords. */
end_comment

begin_define
define|#
directive|define
name|MSTEMP
value|1
end_define

begin_define
define|#
directive|define
name|MSRCDATA
value|2
end_define

begin_define
define|#
directive|define
name|MSCDATA
value|3
end_define

begin_define
define|#
directive|define
name|MSIGNORE
value|4
end_define

end_unit

