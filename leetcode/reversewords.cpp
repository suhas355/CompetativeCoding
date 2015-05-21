/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the". 

*/





    public String reverseWords(String s) {
        if(s==null)
           return null;
        if(s.trim().length()==0)
           return "";
        s=s.trim();   
        String p[]=s.split("\\s+");
        String t = "";
       for(int i=p.length-1;i>0;i--){
           t+=p[i]+" ";
       }
       t+=p[0];
       return t;
        
    }


int main(){
  
  return 0;
}