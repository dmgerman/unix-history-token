begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mac.h	1.1	86/02/25	*/
end_comment

begin_comment
comment|/*  *	UNIX debugger  */
end_comment

begin_define
define|#
directive|define
name|TYPE
value|typedef
end_define

begin_define
define|#
directive|define
name|STRUCT
value|struct
end_define

begin_define
define|#
directive|define
name|UNION
value|union
end_define

begin_define
define|#
directive|define
name|REG
value|register
end_define

begin_define
define|#
directive|define
name|BEGIN
value|{
end_define

begin_define
define|#
directive|define
name|END
value|}
end_define

begin_define
define|#
directive|define
name|IF
value|if(
end_define

begin_define
define|#
directive|define
name|THEN
value|){
end_define

begin_define
define|#
directive|define
name|ELSE
value|} else {
end_define

begin_define
define|#
directive|define
name|ELIF
value|} else if (
end_define

begin_define
define|#
directive|define
name|FI
value|}
end_define

begin_define
define|#
directive|define
name|FOR
value|for(
end_define

begin_define
define|#
directive|define
name|WHILE
value|while(
end_define

begin_define
define|#
directive|define
name|DO
value|){
end_define

begin_define
define|#
directive|define
name|OD
value|}
end_define

begin_define
define|#
directive|define
name|REP
value|do{
end_define

begin_define
define|#
directive|define
name|PER
value|}while(
end_define

begin_define
define|#
directive|define
name|DONE
value|);
end_define

begin_define
define|#
directive|define
name|LOOP
value|for(;;){
end_define

begin_define
define|#
directive|define
name|POOL
value|}
end_define

begin_define
define|#
directive|define
name|ANDF
value|&&
end_define

begin_define
define|#
directive|define
name|ORF
value|||
end_define

begin_define
define|#
directive|define
name|TRUE
value|(-1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|LOBYTE
value|0377
end_define

begin_define
define|#
directive|define
name|STRIP
value|0177
end_define

begin_define
define|#
directive|define
name|SP
value|' '
end_define

begin_define
define|#
directive|define
name|TB
value|'\t'
end_define

begin_define
define|#
directive|define
name|EOR
value|'\n'
end_define

begin_define
define|#
directive|define
name|eqstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b)==0)
end_define

end_unit

