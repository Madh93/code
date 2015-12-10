		// $('.my_selector').click(function(){
		//    $.get('http://MY_SERVER_ADDR:3000/data', {}, function(data){
		//         alert(data);
		//    });
		// });
		// $('.my_selector2').click(function(){
		//         alert("hola");
		// });		


$(document).ready(function(){

	alert("bien");

	$('.my_selector2').click(function(){
		$.get('http://localhost:3000/data', {}, function(data){
	         alert(data);
	     });
	 });


}); 