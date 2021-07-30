import './App.css';
import JSONDATA from "./MOCK_DATA.json"
import { useState } from 'react';


function App() {

  const [SearchTerm, setSearchTerm] = useState('')

  return (
   <div className = "App">
     <input type= "text" placeholder = "Search...."/> 
       {JSONDATA.map((val,key)=>{

         return (
           <div className = "user" key = {key}>
             <p>(val.fist_name)</p>
           </div>
         );
       })};
   </div>
  );  
}

export default App;
