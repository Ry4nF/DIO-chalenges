const typeToClass = {
    "Grama": "bg-grass",
    "Fogo": "bg-fire",
    "Água": "bg-water",
    "Elétrico": "bg-electric",
    "Gelo": "bg-ice",
    "Lutador": "bg-fighting",
    "Veneno": "bg-poison",
    "Terra": "bg-ground",
    "Voador": "bg-flying",
    "Psíquico": "bg-psychic",
    "Inseto": "bg-bug",
    "Pedra": "bg-rock",
    "Fantasma": "bg-ghost",
    "Dragão": "bg-dragon",
    "Aço": "bg-steel",
    "Fada": "bg-fairy",
    "Normal": "bg-normal"
};

const cards = document.querySelectorAll('.pokemon-card');

cards.forEach(card => {
    const typeText = card.querySelector('.pokemon-type').textContent; // ✅
    const primaryType = typeText.split('/')[0].trim(); // pega o 1º tipo
    const cssClass = typeToClass[primaryType];
    
    if (cssClass) {
        card.classList.add(cssClass);
    }
});
