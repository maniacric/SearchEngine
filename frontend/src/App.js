import './App.css';
import JSONDATA from "./MOCK_DATA.json"
import { useState } from 'react';


function App() {

  const [SearchTerm, setSearchTerm] = useState('')

  return (
   <div className = "App">
     <input 
      type= "text" 
      placeholder = "Search...." 
      onChange = {(event) =>{
        setSearchTerm(event.target.value)
        }}/> 
       {JSONDATA.filter((val)=>{
         if(SearchTerm=="")
          return val;
        else if(val.first_name.toLocaleLowerCase().includes(SearchTerm.toLowerCase())){
          return val;
        }
       }).map((val,key) => {
         return (
           <div className = "user" key = {key}>
             <p>{val.first_name}</p>
           </div>
         );
       })};
   </div>
  );  
}

export default App;
