begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* 	This file corresponds to the following network:  				A 				| 				| 				| 				| 		Cory------------C--------------D 		 |		|	       | 		 |		|	       | 		 |		|	       | 		 |		|	       | 		VAX		E	      SRC  	The tables must be consistent. */
end_comment

begin_decl_stmt
name|char
name|configA
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configB
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configC
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|000
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configD
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'s'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configE
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configI
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configQ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configS
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'s'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configV
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|configY
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table is used by netlpr to do lpr w/o an acct    and by net and netdaemon to do pre-emption */
end_comment

begin_comment
comment|/* sub.c uses the table in initdaemon to check machine    type - errormsg may be ignored */
end_comment

begin_decl_stmt
name|char
name|machtype
index|[]
init|=
block|{
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
comment|/* a,b,c,d,e */
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|M_INGRES
block|,
literal|0
block|,
comment|/* f,g,h,i,j */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* k,l,m,n,o */
literal|0
block|,
name|M_CC
block|,
literal|0
block|,
name|M_SRC
block|,
literal|0
block|,
comment|/* p,q,r,s,t */
literal|0
block|,
name|M_VAX
block|,
literal|0
block|,
literal|0
block|,
name|M_CORY
block|,
comment|/* u,v,w,x,y */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z */
end_comment

begin_comment
comment|/* this is basically the default machine for each local machine */
end_comment

begin_decl_stmt
name|char
name|remtable
index|[]
init|=
block|{
literal|'c'
block|,
literal|'c'
block|,
literal|'a'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
literal|000
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|000
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad login names */
end_comment

begin_decl_stmt
name|struct
name|bstruct
name|btable
index|[]
init|=
block|{
literal|"op"
block|,
literal|'a'
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table shows the correspondence between    machine names like 'Cory' and their internal    names, like 'y' */
end_comment

begin_struct
specifier|static
struct|struct
name|tt
block|{
name|char
modifier|*
name|bigname
decl_stmt|;
name|char
name|lname
decl_stmt|;
block|}
name|table
index|[]
init|=
block|{
literal|"A"
block|,
literal|'a'
block|,
literal|"B"
block|,
literal|'b'
block|,
literal|"C"
block|,
literal|'c'
block|,
literal|"D"
block|,
literal|'d'
block|,
literal|"E"
block|,
literal|'e'
block|,
literal|"INGRES"
block|,
literal|'i'
block|,
literal|"Q"
block|,
literal|'q'
block|,
literal|"SRC"
block|,
literal|'s'
block|,
literal|"VAX"
block|,
literal|'v'
block|,
literal|"Cory"
block|,
literal|'y'
block|,
literal|0
block|,
literal|0
block|}
struct|;
end_struct

end_unit

