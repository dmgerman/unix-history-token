begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * C library -- alloc/free  */
end_comment

begin_define
define|#
directive|define
name|logical
value|int
end_define

begin_struct
struct|struct
name|fb
block|{
name|logical
name|size
decl_stmt|;
name|char
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|freelist
index|[]
init|=
block|{
literal|0
block|,
operator|-
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|logical
name|slop
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_macro
name|alloc
argument_list|(
argument|asize
argument_list|)
end_macro

begin_decl_stmt
name|logical
name|asize
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|calloc
argument_list|(
literal|1
argument_list|,
name|asize
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*{ 	register logical size; 	register logical np; 	register logical cp;  	if ((size = asize) == 0) 		return(0); 	size += 3; 	size&= ~01; 	for (;;) { 		cp = freelist; 		while ((np = cp->next) != -1) { 			if (np->size>=size) { 				if (size+slop>= np->size) { 					cp->next = np->next; 					return(&np->next); 				} 				cp = cp->next = np+size; 				cp->size = np->size - size; 				cp->next = np->next; 				np->size = size; 				return(&np->next); 			} 			cp = np; 		} 		return ( calloc ( 1 , asize ) );   		/* asize = size<1024? 1024: size; 		if ((cp = sbrk(asize)) == -1) { 			error("workspace exceeded");  		} 		cp->size = asize; 		free(&cp->next);  	} }  */
end_comment

begin_macro
name|afree
argument_list|(
argument|aptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|aptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|aptr
operator|==
literal|0
condition|)
return|return;
name|cfree
argument_list|(
name|aptr
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* { 	register logical ptr; 	register logical cp; 	register logical np;  	if (aptr == 0) return; 	ptr = aptr-4; 	cp = freelist; 	while ((np = cp->next)< ptr) 		cp = np; 	if (ptr+ptr->size == np) { 		ptr->size += np->size; 		ptr->next = np->next; 		np = ptr; 	} else 		ptr->next = np; 	if (cp+cp->size == ptr) { 		cp->size += ptr->size; 		cp->next = ptr->next; 	} else 		cp->next = ptr; } */
end_comment

end_unit

