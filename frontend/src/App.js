import './App.css';
import JSONDATA from "./MOCK_DATA.json"


function App() {
  return (
   <div className = "App">
     <input type= "text" placeholder = "Search...."/> 
       {JSONDATA.map((val,key)=>{
           let t = val;
         return (
           <div className = "user" key = {key}>
             <p>(t.fist_name)</p>
           </div>
         );
       })};
   </div>
  );  
}

export default App;
