begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|numeric
parameter_list|(
name|c
parameter_list|)
value|(c>='0'&& c<='9')
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a<b ? b : a)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a>b ? b : a)
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|(x<0 ? -x : x)
end_define

begin_define
define|#
directive|define
name|copy
parameter_list|(
name|src
parameter_list|,
name|dest
parameter_list|)
value|strcpy(dest,src)
end_define

begin_define
define|#
directive|define
name|compare
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
value|strcmp(str1,str2)
end_define

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
value|!strcmp(str1,str2)
end_define

begin_define
define|#
directive|define
name|length
parameter_list|(
name|str
parameter_list|)
value|strlen(str)
end_define

begin_define
define|#
directive|define
name|size
parameter_list|(
name|str
parameter_list|)
value|(1+strlen(str))
end_define

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_include
include|#
directive|include
file|"sys/stat.h"
end_include

begin_decl_stmt
name|struct
name|stat
name|Statbuf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|exists
parameter_list|(
name|file
parameter_list|)
value|(stat(file,&Statbuf)<0 ? 0:Statbuf.st_mode)
end_define

begin_define
define|#
directive|define
name|xfopen
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
value|fdopen(xopen(file,mode),mode==0?"r":mode==1?"w":"r+w")
end_define

begin_define
define|#
directive|define
name|xfcreat
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
value|fdopen(xcreat(file,mode),"w")
end_define

begin_define
define|#
directive|define
name|remove
parameter_list|(
name|file
parameter_list|)
value|xunlink(file)
end_define

begin_define
define|#
directive|define
name|SCCSID
parameter_list|(
name|arg
parameter_list|)
value|static char Sccsid[] = "arg"
end_define

begin_define
define|#
directive|define
name|USXALLOC
parameter_list|()
end_define

begin_define
define|#
directive|define
name|NONBLANK
parameter_list|(
name|p
parameter_list|)
value|while (*p==' ' || *p=='\t') p++
end_define

begin_decl_stmt
name|char
name|Null
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Error
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

end_unit

