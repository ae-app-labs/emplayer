/* SkinChanger for eMplayer2 - copies files from skin dirs to main dir
 * (c) 2006 October Centrum inc Software Solutions
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

 *	$Id V 1.1
 */

# include <stdio>
# include <conio>
# include <stdlib>
# include <string>

// changeSkinDir.exe <skinCode>

void main(int argc, char *argv[])
{
	if(argc==2)
   {
   	char *tmpCmdFile ="skins\\change.bat";	// the temp command file
   	FILE *fp = fopen(tmpCmdFile,"w");		// open that file

/* Populate the batch file */
      fputs("@ECHO OFF\n",fp);
      fputs("cd skins \n",fp);
      fputs("cd ",fp);
      fputs(argv[1],fp);
      fputs("\ncopy *.* ..\\current\\ ",fp);
      fclose(fp);
/* Execute the file*/
      system(tmpCmdFile);
/* Hey nothing happened here!*/
      remove(tmpCmdFile);
   }
}
