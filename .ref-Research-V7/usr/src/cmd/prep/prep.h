begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NUMC
value|128
end_define

begin_define
define|#
directive|define
name|NUMS
value|3
end_define

begin_define
define|#
directive|define
name|NUMA
value|8
end_define

begin_define
define|#
directive|define
name|PTRI
value|1600
end_define

begin_define
define|#
directive|define
name|CHARI
value|16000
end_define

begin_define
define|#
directive|define
name|OUT
value|3
end_define

begin_define
define|#
directive|define
name|SKIP
value|0
end_define

begin_define
define|#
directive|define
name|COLLECT
value|1
end_define

begin_define
define|#
directive|define
name|SKIP2
value|2
end_define

begin_define
define|#
directive|define
name|WIDTH
value|6
end_define

begin_struct
struct|struct
block|{
name|char
modifier|*
name|beg
decl_stmt|;
name|int
name|ct
decl_stmt|;
name|long
name|wdno
decl_stmt|;
block|}
name|temp
index|[
literal|30
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|puncfl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hsw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|san
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tab
index|[
name|NUMS
index|]
index|[
name|NUMC
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|coll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hyphen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hyp1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hyp2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsp1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gobble2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bslash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|punc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|line
index|[
literal|300
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|only
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|flag
index|[
literal|8
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|fl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wdflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|wdnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|num
index|[
name|WIDTH
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|igflg
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|htab
block|{
name|int
name|hsiz
decl_stmt|;
name|int
name|ssiz
decl_stmt|;
name|int
name|nsym
decl_stmt|;
name|int
name|curb
decl_stmt|;
name|int
modifier|*
name|hptr
decl_stmt|;
name|char
modifier|*
name|symt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|htab
name|itab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipsp
index|[
name|PTRI
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|issp
index|[
name|CHARI
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fi
decl_stmt|;
end_decl_stmt

end_unit

