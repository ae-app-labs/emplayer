/* eMplayer 2.7 playlist editor
 * Commandline program for editing the playlist and index
 * Copyright (c) 2006 October Centrum inc Software Solutions
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * http://www.geocities.com/mhkonine2/
 * midhunhk@gmail.com
 *
 * $Id 1.5.7
 */

//  listed.mpi index for playlists. stores the names of all the existing playlists
//	 *.mpl	the playlist files. each file has a corresponding entry in the index file

# include <conio>
# include <stdio>
# include <string>

int xstrsearch(char *,char *);

// editpl.exe W filename <song1path>*<song2path>*....
// editpl.exe O filename <song1path>*<song2path>*....
// editpl.exe D filename

void main(int argc, char *argv[])
{
       if(argc >= 3)
      {
   	FILE *fi = fopen("playlists/listed.mpi","a");
             FILE *fp;
             char plistFile[64],indexContents[256],ch;
      	plistFile[0] ='\0';
	   strcat(plistFile,"playlists/");
   	   strcat(plistFile,argv[2]);
      	   strcat(plistFile,".mpl");
	      fp = fopen(plistFile,"w");
      if(strcmp(argv[1],"O")==0) // overwrite the playlist file
        { fputs(argv[3],fp); fclose(fp);fclose(fi);}

   	else if(strcmp(argv[1],"W")==0) // write and add to index file
        { fprintf(fi,"%s*",argv[2]);fclose(fi);
          fputs(argv[3],fp); fclose(fp);}

      else if(strcmp(argv[1],"D")==0)
        {
          fclose(fp);int len,i=0;
          remove(plistFile); // delete the mpl file
          len = strlen(argv[2]);
// now remove the entry for the file from the index
          fclose(fi);
          fi = fopen("playlists/listed.mpi","r");  fseek(fi,0,SEEK_SET);
          while((ch=fgetc(fi))!=EOF){indexContents[i++] = ch;}
          indexContents[i] ='\0';
          fclose(fi);
          int l2 = strlen(indexContents);
          fi = fopen("playlists/listed.mpi","w");
         int startPos = xstrsearch(indexContents,argv[2]);
         /* assumes that entry does exist coz this same prog is used to write the idex file.*/
          for(i=0;i<startPos;i++)
     	fputc(indexContents[i],fi);
          int endPos = startPos+len+1;
          for(i=endPos;i<l2;i++)
          	fputc(indexContents[i],fi);
          fclose(fi);
        }
	}
        else {printf("Edit Playlist for eMplayer2.7\n\n format : <editpl.exe> <mode> <filename> <songpaths>");}
}

// BRUTEFORCE ALGORITHM searches for a substring
int xstrsearch(char *s1,char *s2)
{
  int i,j,k;
  int l1 =  strlen(s1);
  int l2 =  strlen(s2);

  for(i=0;i<=l1-l2;i++)
  {
  	j = 0;
   k = i;
   while((s1[k] == s2[j])&&(j<l2))
   	{	k++; j++;}
   if(j==l2) return i;
  }
  return -1;
}
